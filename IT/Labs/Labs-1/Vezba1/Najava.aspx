<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Najava.aspx.cs" Inherits="Vezba1._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
       <section class="jumbotron">
           <h1>Labs-1</h1>
       </section>
        <br />
        <section class="container text-center">
            <div class="col-md-12">
                <div class="m-3">
                    <label class="mx-4">Име</label> <asp:TextBox ID="txtBoxName" runat="server"></asp:TextBox> <asp:RequiredFieldValidator ID="validateName" runat="server" ErrorMessage="Внесете име" CssClass="text-danger mx-3" ControlToValidate="txtBoxName"></asp:RequiredFieldValidator>
                </div>
                <div class="m-3">
                    <label class="mx-4">Лозинка</label> <asp:TextBox ID="txtBoxPassword" runat="server" TextMode="Password"></asp:TextBox><asp:RequiredFieldValidator ID="validatePassword" runat="server" ErrorMessage="Внесете лозинка" CssClass="text-danger mx-3" ControlToValidate="txtBoxPassword"></asp:RequiredFieldValidator>
                </div>
                <div class="m-3">
                    <label class="mx-4">Е-адреса</label> <asp:TextBox ID="txtBoxEmail" runat="server" TextMode="Email"></asp:TextBox><asp:RegularExpressionValidator ID="validateEmail" runat="server" ErrorMessage="Невалиден формат" CssClass="text-danger mx-3" ControlToValidate="txtBoxEmail" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator>
                </div>
                <div class="m-3">
                    <asp:Button ID="btnSignin" runat="server" Text="Најавете се" OnClick="btnSignin_Click"/>
                </div>
            </div>
        </section>
    </main>

</asp:Content>
