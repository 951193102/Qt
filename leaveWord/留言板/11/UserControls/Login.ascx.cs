﻿using System;
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
            Response.Redirect("ReleaseWord.aspx");
            dr.Close();
        }
        dr.Close();
        string cmdtxt1 = "SELECT * FROM tb_User WHERE Uid='" + this.txtUid.Text.Trim() + "' AND Pwd='" + this.txtPwd.Text.Trim() + "'";
        SqlDataReader dr1 = da.ExceRead(cmdtxt1);
        dr1.Read();
        if (dr1.HasRows)
        {
            Session["UserName"] = dr1["Uid"].ToString();
            Session["ID"] = dr1["ID"].ToString();
            Response.Redirect("ReleaseWord.aspx");
        }
        dr1.Close();
    }
}
