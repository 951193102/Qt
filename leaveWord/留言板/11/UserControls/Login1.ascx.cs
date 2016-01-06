using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

using System.Data.SqlClient;

public partial class UserControls_Login : System.Web.UI.UserControl
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btnOK_Click(object sender, EventArgs e)
    {
        SqlData da = new SqlData();
        string cmdtxt = "SELECT * FROM tb_User WHERE Uid='"+this.txtUid.Text.Trim()+"' AND Pwd='"+this.txtPwd.Text.Trim()+"' AND Popedom=1";
        SqlDataReader dr = da.ExceRead(cmdtxt);
        dr.Read();
        if (dr.HasRows)
        {
            Session["UserName"] = dr["Uid"].ToString();
            Session["ID"] = dr["ID"].ToString();
            Response.Redirect("LeaveWordManage.aspx");
            dr.Close();
        }
        else
        {
            Response.Write("<script>alert('用户名或密码错误！');location='Login1.aspx'</script>");
        }
        dr.Close();
    }
}
