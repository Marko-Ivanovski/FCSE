import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

// ENUM
enum FuelType {
    ELECTRIC("Electric"),
    PETROL("Petrol"),
    DIESEL("Diesel"),
    HYBRID("Hybrid");

    private final String name;

    FuelType (String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
}
// Abstract Class
abstract class Vehicle {
    private String model;
    private double weightKg;
    private String fuelType;
    private int maxSpeed;
    private double rating;
    private int seatingCapacity;

    public Vehicle(String model, double weightKg, String fuelType, int maxSpeed, double rating, int seatingCapacity) {
        this.model = model;
        this.weightKg = weightKg;
        this.fuelType = fuelType;
        this.maxSpeed = maxSpeed;
        this.rating = rating;
        this.seatingCapacity = seatingCapacity;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public double getWeightKg() {
        return weightKg;
    }

    public void setWeightKg(double weightKg) {
        this.weightKg = weightKg;
    }

    public String getFuelType() {
        return fuelType;
    }

    public void setFuelType(String fuelType) {
        this.fuelType = fuelType;
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public void setMaxSpeed(int maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public double getRating() {
        return rating;
    }

    public void setRating(double rating) {
        this.rating = rating;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    @Override
    public String toString() {
        return "Vehicle{" +
                "model='" + model + '\'' +
                ", weightKg=" + weightKg +
                ", fuelType='" + fuelType + '\'' +
                ", maxSpeed=" + maxSpeed +
                ", rating=" + rating +
                ", seatingCapacity=" + seatingCapacity +
                '}';
    }
}

// Extended Classes
class Car extends Vehicle {
    private String bodyType;

    public Car(String model, double weightKg, String fuelType, int maxSpeed, double rating, int seatingCapacity, String bodyType) {
        super(model, weightKg, fuelType, maxSpeed, rating, seatingCapacity);
        this.bodyType = bodyType;
    }

    public String getBodyType() {
        return bodyType;
    }

    public void setBodyType(String bodyType) {
        this.bodyType = bodyType;
    }

    @Override
    public String toString() {
        return "Car{" +
                "bodyType='" + bodyType + '\'' +
                ", " + super.toString() +'}';
    }
}

class Motorcycle extends Vehicle {
    private boolean hasSideCar;

    public Motorcycle(String model, double weightKg, String fuelType, int maxSpeed, double rating, int seatingCapacity, boolean hasSideCar) {
        super(model, weightKg, fuelType, maxSpeed, rating, seatingCapacity);
        this.hasSideCar = hasSideCar;
    }

    public boolean isHasSideCar() {
        return hasSideCar;
    }

    public void setHasSideCar(boolean hasSideCar) {
        this.hasSideCar = hasSideCar;
    }

    @Override
    public String toString() {
        return "Motorcycle = {" +
                "hasSideCar =" + hasSideCar +
                ", " + super.toString() +
                '}';
    }
}

class Truck extends Vehicle {
    private int cargoCapacity;

    public Truck(String model, double weightKg, String fuelType, int maxSpeed, double rating, int seatingCapacity, int cargoCapacity) {
        super(model, weightKg, fuelType, maxSpeed, rating, seatingCapacity);
        this.cargoCapacity = cargoCapacity;
    }

    public int getCargoCapacity() {
        return cargoCapacity;
    }

    public void setCargoCapacity(int cargoCapacity) {
        this.cargoCapacity = cargoCapacity;
    }

    @Override
    public String toString() {
        return "Truck = {" +
                "cargoCapacity =" + cargoCapacity +
                ", " + super.toString() +
                '}';
    }
}

// Vehicle Partitioner
class VehiclePartitioner{
    public static Map<Boolean, List<Vehicle>> partitionVehicles(List<Vehicle> vehicles, Predicate<Vehicle> predicate) {
        return vehicles.stream().collect(Collectors.partitioningBy(predicate));
    }
}

// Vehicle Finder
class VehicleFinder {
    public static List<Vehicle> uniqueVehicles(List<Vehicle> vehicles) {
        return vehicles.stream().distinct().collect(Collectors.toList());
    }

    public static List<Vehicle> nonUniqueVehicles(List<Vehicle> vehicles) {
        List<Vehicle> uniqueVehicles = uniqueVehicles(vehicles);
        return vehicles.stream().filter(vehicle -> !uniqueVehicles.contains(vehicle)).toList();
    }
}

// Vehicle Grouper
class VehicleGrouper {
    public static Map<String, List<Vehicle>> groupByFuelType(List<Vehicle> vehicles) {
        return vehicles.stream().collect(Collectors.groupingBy(Vehicle::getFuelType));
    }

    public static Map<Integer, List<Vehicle>> groupBySeatingCapacity(List<Vehicle> vehicles) {
        return vehicles.stream().collect(Collectors.groupingBy(Vehicle::getSeatingCapacity));
    }

    public static Map<String, List<Vehicle>> groupBySpeed(List<Vehicle> vehicles) {
        return vehicles.stream().collect(Collectors.groupingBy(v -> {
            if (v.getMaxSpeed() < 100){
                return "Slow";
            }
            if (v.getMaxSpeed() > 100 && v.getMaxSpeed() < 200){
                return "Medium";
            }
            else {
                return "Fast";
            }
        }));
    }
}

// Random Vehicle Generator
class RandomGenerator {
    private static Random random = new Random();

    private static final String[] models = {"Tesla Model S", "Nissan Qashqai", "Ford F150", "Harley Davidson"};
    private static final String[] fuelTypes = {"Electric", "Hybrid", "Petrol", "Diesel"};
    private static final String[] bodyTypes = {"Sedan", "SUV", "Motorcycle", "Truck"};

    public static List<Vehicle> generateVehicles() {
        List<Vehicle> vehicles = new ArrayList<>();

        String model = models[random.nextInt(models.length)];
        String fuelType = fuelTypes[random.nextInt(fuelTypes.length)];
        String bodyType = bodyTypes[random.nextInt(bodyTypes.length)];
        int seatingCapacity = random.nextInt(2, 7);
        double rating = random.nextDouble(1, 10);
        double weightKg = random.nextInt(500, 5000);
        int maxSpeed = random.nextInt(50, 350);

        if (bodyType.equals("Sedan") || bodyType.equals("SUV")) {
            vehicles.add(new Car(model, weightKg, fuelType, maxSpeed, rating, seatingCapacity, bodyType));
        } else if (bodyType.equals("Motorcycle")) {
            boolean hasSideCar = random.nextBoolean();
            vehicles.add(new Motorcycle(model, weightKg, fuelType, maxSpeed, rating, seatingCapacity, hasSideCar));
        } else if (bodyType.equals("Truck")) {
            int cargoCapacity = random.nextInt(1000, 5000);
            vehicles.add(new Truck(model, weightKg, fuelType, maxSpeed, rating, seatingCapacity, cargoCapacity));
        }

        return vehicles;
    }
}

// Pairing Vehicles
class VehiclePairing {
    public static List<String> pairBestAndWorstVehicles(List<Vehicle> vehicles) {
        List<Vehicle> bestRated = vehicles.stream().sorted(Comparator.comparingDouble(Vehicle::getRating).reversed()).toList();
        List<Vehicle> worstRated = vehicles.stream().sorted(Comparator.comparingDouble(Vehicle::getRating)).toList();

        List<Vehicle> pairedVehicles = new ArrayList<>();
        for (int i = 0; i < vehicles.size() / 2; i++) {
            pairedVehicles.add(bestRated.get(i));
            pairedVehicles.add(worstRated.get(i));
        }
        return pairedVehicles.stream().map(Vehicle::getModel).collect(Collectors.toList());
    }
}

// Vehicle Comparison
class VehicleComparing {
    public static int compareVehicles(Vehicle v1, Vehicle v2) {
        int weightComparison = Double.compare(v1.getWeightKg(), v2.getWeightKg());
        if (weightComparison != 0) {
            return weightComparison;
        }

        int speedComparion = Integer.compare(v1.getMaxSpeed(), v2.getMaxSpeed());
        if (speedComparion != 0) {
            return speedComparion;
        }

        List<String> fuelTypes = Arrays.asList("Electric", "Hybrid", "Petrol", "Diesel");
        int fuelTypeCompariosn = fuelTypes.indexOf(v1.getFuelType()) - fuelTypes.indexOf(v2.getFuelType());
        if (fuelTypeCompariosn != 0) {
            return fuelTypeCompariosn;
        }

        return Integer.compare(v1.getSeatingCapacity(), v2.getSeatingCapacity());
    }
}

public class Main {
    public static void main(String[] args) {
        // List of vehicles
        List<Vehicle> vehicles = new ArrayList<>();

        // Vehicle Partitioner by Electric FuelType
        Map<Boolean, List<Vehicle>> electricPartition = VehiclePartitioner.partitionVehicles(vehicles, e -> e.getFuelType().equals("Electric"));

        List<Vehicle> electricVehicles = electricPartition.get(true);
        System.out.println(electricVehicles);

        List<Vehicle> nonElectricVehicles = electricPartition.get(false);
        System.out.println(nonElectricVehicles);

        //
    }
}