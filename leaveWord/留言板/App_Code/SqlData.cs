using System;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using System.Data.SqlClient;
/// <summary>
///SqlData 的摘要说明
/// </summary>
public class SqlData
{
    private SqlConnection sqlcon;
    private SqlCommand sqlcom;
    private SqlDataAdapter sqldata;
	public SqlData()
	{
        sqlcon = new SqlConnection(ConfigurationManager.AppSettings["ConSql"]);
        sqlcon.Open();
	}
    public bool ExceSql(string SqlCom)
    {
        sqlcom = new SqlCommand(SqlCom, sqlcon);
        try
        {
            sqlcom.ExecuteNonQuery();
            return true;
        }
        catch
        {
            return false;
        }
        finally
        {
            sqlcon.Close();
        }
    }

    public DataSet ExceDs(string SqlCom)
    {
        try
        {
            sqlcom = new SqlCommand(SqlCom, sqlcon);
            sqldata = new SqlDataAdapter();
            sqldata.SelectCommand = sqlcom;
            DataSet ds = new DataSet();
            sqldata.Fill(ds);
            return ds;
        }
        finally
        {
            sqlcon.Close();
        }
    }
    public SqlDataReader ExceRead(string SqlCom)
    {
        sqlcom = new SqlCommand(SqlCom, sqlcon);
        SqlDataReader read = sqlcom.ExecuteReader();
        return read;
    }
}
