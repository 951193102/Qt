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

using System.Data.SqlClient;

public partial class Default3 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            SqlConnection Con = new SqlConnection(ConfigurationManager.AppSettings["ConSql"]);
            Con.Open();
            string id = Request["ID"].ToString();
            string cmdtxt = "SELECT * FROM tb_LeaveWord WHERE ID=" + id + "";
            SqlData da = new SqlData();
            SqlCommand Com = new SqlCommand(cmdtxt, Con);
            SqlDataReader dr = Com.ExecuteReader();
            dr.Read();
            if (dr.HasRows)
            {
                this.txtSubject.Text = dr["Subject"].ToString();
            }
            dr.Close();
        }
    }
    protected void btnOK_Click(object sender, EventArgs e)
    {
        SqlData da = new SqlData();
        string cmdtxt = "INSERT INTO tb_Reply(UName,Content,DateTime,ReplyID,IP)";
        cmdtxt += "VALUES('" + this.txtUid.Text + "','" + this.FreeTextBox1.Text + "','" + DateTime.Now + "'";
        cmdtxt += "," + Request["ID"].ToString() + ",'" + Request.UserHostAddress + "')";
        if (da.ExceSQL(cmdtxt))
        {
            Response.Write("<script language=javascript>alert('操作成功！');location='LeaveWordView.aspx?ID="+Request["ID"]+"'</script>");
        }
        else
        {
            Response.Write("<script language=javascript>alert('操作失败！')</script>");
        }
    }
}
