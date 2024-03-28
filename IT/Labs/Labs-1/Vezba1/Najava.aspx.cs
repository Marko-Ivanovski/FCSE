using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vezba1 {
    public partial class _Default : Page {
        protected void Page_Load(object sender, EventArgs e) {

        }

        protected void btnSignin_Click(object sender, EventArgs e) {
            Session["Value"] = txtBoxEmail.Text;
            if (txtBoxName.Text != null && txtBoxPassword.Text != null && txtBoxEmail.Text != null) {
                Response.Redirect("Glasaj.aspx");
            }
        }
    }
}