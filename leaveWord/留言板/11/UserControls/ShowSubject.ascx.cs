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
using System.Data.SqlClient;  //添加引用

public partial class UserControls_ShowWord : System.Web.UI.UserControl
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    public string GetList()
    {
        SqlData da = new SqlData();
        SqlDataReader dr = da.ExceRead("select * from tb_LeaveWord ");
        string strBody = "<table width=150>";
        while (dr.Read())//循环读取
        {
            strBody += "<tr><td class=tableBottom>·<a href=ShowWord.aspx?ID=" + dr["ID"] + " >" + dr["Subject"].ToString() + "</a></td></tr>\n";
        }
        dr.Close();//关闭阅读器
        strBody += "</table>";
        return strBody;
    }
}
