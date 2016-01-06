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

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["UserName"] == null)
        {
            Response.Redirect("Login.aspx");
        }
    }

    protected void btnOK_Click(object sender, EventArgs e)
    {
        SqlData da = new SqlData();
        string cmdtxt = "INSERT INTO tb_LeaveWord(Uid,Subject,Content,DateTime,IP)";
        cmdtxt += " VALUES('" + Session["UserName"].ToString()+ "','" + this.TextBox1.Text + "'";
        cmdtxt += ",'"+this.FreeTextBox1.Text+"','" + DateTime.Now+ "'";
        cmdtxt += ",'" + Request.UserHostAddress + "')";
        bool add = da.ExceSQL(cmdtxt);
        if (add == true)
        {
            Response.Write("<script language=javascript>alert('添加成功!');location='Default.aspx'</script>");
        }
        else
        {
            Response.Write("<script language=javascript>alert('添加失败！');location='javascript:history.go(-1)'</script>");
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        this.TextBox1.Text = "";
        this.FreeTextBox1.Text = "";
    }
}
