<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Glasaj.aspx.cs" Inherits="Vezba1.WebForm1" %>

<asp:Content ID="Glasaj" ContentPlaceHolderID="MainContent" runat="server">

    <main>
       <section class="jumbotron">
           <h1>Labs-1</h1>
       </section>
       <br />
        <section class="container">
            <div class="col-md-12">
                 <div class="m-3">
                     <asp:Image ID="logo" runat="server" ImageUrl="~/App_Data/finki_52_1_2_1_62_0.png" />
                     <br />
                     <asp:Label ID="lblProfеsor" runat="server" Text=""></asp:Label>
                 </div>
                <div class="m-3">
                    <asp:ListBox ID="lbPredmeti" runat="server" AutoPostBack="True" OnSelectedIndexChanged="lbPredmeti_SelectedIndexChanged">
                    </asp:ListBox>
                    <asp:ListBox ID="lbKrediti" runat="server">
                    </asp:ListBox>
                </div>
                <div class="m-3">
                    <asp:Button ID="btnGlasaj" runat="server" Text="Гласајте" OnClick="btnGlasaj_Click"/>
                </div>
                <hr />
                <div class="m-3">
                    <label>Предмет:</label><br />
                    <asp:TextBox runat="server" ID="txtBoxSubject"></asp:TextBox>
                </div>
                <div class="m-3">
                    <label>Кредити:</label><br />
                    <asp:TextBox runat="server" ID="txtBoxCredits"></asp:TextBox>
                </div>
                <br />
                <div class="m-3">
                    <asp:Button ID="btnAdd" runat="server" Text="Додади" OnClick="btnAdd_Click" />
                </div>
                <div class="m-3">
                    <asp:Button ID="btnRemove" runat="server" Text="Избриши" OnClick="btnRemove_Click" />
                </div>
            </div>
        </section>
    </main>

</asp:Content>
