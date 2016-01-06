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

public partial class UserControls_Register : System.Web.UI.UserControl
{
    protected void Page_Load(object sender, EventArgs e)
    {
    }
    protected void btnOK_Click(object sender, EventArgs e)
    {
        this.MultiView1.ActiveViewIndex = 1;
    }

    protected void btnOK1_Click(object sender, EventArgs e)
    {
        SqlData da = new SqlData();
        SqlDataReader read = da.ExceRead("select * from tb_User where Uid='" + this.txtUid.Text + "'");
        read.Read();
        if (read.HasRows)
        {
            if (this.txtUid.Text == read["Uid"].ToString())
            {
                Response.Write("<script language=javascript>alert('对不起，该用户已经注册！');location='Register.aspx'</script>");
                return;
            }
        }
        read.Close();
        string cmdtxt = "INSERT INTO tb_User(Uid,Pwd,Sex,WebSite,Email,QQ,IP)";
        cmdtxt += " VALUES('" + this.txtUid.Text + "','" + this.txtPwd.Text + "','" + this.radSex.SelectedValue+ "'";
        cmdtxt += ",'" + this.txtWebSite.Text + "','" + this.txtEmail.Text + "','" + this.txtQQ.Text + "'";
        cmdtxt += ",'" + Request.UserHostAddress + "')";
        
        bool add = da.ExceSQL(cmdtxt);
        if (add == true)
        {
            Response.Write("<script language=javascript>alert('注册成功!');location='Register.aspx'</script>");
        }
        else
        {
            Response.Write("<script language=javascript>alert('注册失败！');location='javascript:history.go(-1)'</script>");
        }
    }

    protected void btnNoOK_Click(object sender, EventArgs e)
    {
        Response.Redirect("Index.aspx");
    }
}
