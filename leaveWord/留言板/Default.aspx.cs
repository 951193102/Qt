using System;
using System.Collections;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using System.Data.SqlClient;
public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    public string GetList()
    {
        SqlData da = new SqlData();
        SqlDataReader dr = da.ExceRead("select * from tb_LeaveWord");
        string strBody = "<table width=200>";
        while (dr.Read())
        {
            strBody += "<tr><td>● <a href= >" + dr["Subject"].ToString() + "</a></td></tr>\n";
        }
        dr.Close();
        strBody += "</table>";
        return strBody;
    }
}
