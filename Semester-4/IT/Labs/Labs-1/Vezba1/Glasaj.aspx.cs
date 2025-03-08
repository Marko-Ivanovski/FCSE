using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vezba1 {
    public partial class WebForm1 : System.Web.UI.Page {
        protected void Page_Load(object sender, EventArgs e) {
            if (!IsPostBack) {
                // Only populate the list boxes if it's not a postback
                PopulateListBoxes();
            }
        }

        protected void btnGlasaj_Click(object sender, EventArgs e) {
            // Redirect only if both list boxes have a selection
            if (lbPredmeti.SelectedIndex != -1 && lbKrediti.SelectedIndex != -1) {
                Response.Redirect("UspesnoGlasanje.aspx");
            }
        }

        protected void lbPredmeti_SelectedIndexChanged(object sender, EventArgs e) {
            // When an item is selected in lbPredmeti, select the corresponding item in lbKrediti
            // Make sure the selected index is within range
            if (lbPredmeti.SelectedIndex >= 0 && lbPredmeti.SelectedIndex < lbKrediti.Items.Count) {
                lbKrediti.SelectedIndex = lbPredmeti.SelectedIndex;
                lblProfеsor.Text = lbPredmeti.SelectedValue;
            }
        }

        protected void btnAdd_Click(object sender, EventArgs e) {
            // Add the entered subject and credits to the list boxes
            lbPredmeti.Items.Add(new ListItem(txtBoxSubject.Text, txtBoxCredits.Text));
            lbKrediti.Items.Add(new ListItem(txtBoxCredits.Text));
        }

        protected void btnRemove_Click(object sender, EventArgs e) {
            // Remove the selected items from both list boxes
            for (int i = lbPredmeti.Items.Count - 1;i >= 0;i--) {
                if (lbPredmeti.Items[i].Selected) {
                    lbPredmeti.Items.RemoveAt(i);
                    lbKrediti.Items.RemoveAt(i);
                }
            }
        }

        private void PopulateListBoxes() {
            // Populate the list boxes with predefined items
            lbPredmeti.Items.Add(new ListItem("Интернет Технологи", "Проф. д-р Мерем Мереми"));
            lbPredmeti.Items.Add(new ListItem("Хејање", "Miro"));
            lbKrediti.Items.Add("6");
            lbKrediti.Items.Add("9");
        }
    }
}