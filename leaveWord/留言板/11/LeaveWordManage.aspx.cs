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

public partial class Default2 : System.Web.UI.Page
{
    public string ShowSubject, ShowTime, ShowContent;  //声明的变量

    protected void Page_Load(object sender, EventArgs e)
    {

        if (Session["UserName"] == null)
        {
            Response.Redirect("Login.aspx");
        }
        this.dlBind();
    }
    public void dlBind()
    {
        string id = null; 
        SqlData da = new SqlData();
        int curpage = Convert.ToInt32(labNowPage.Text);
        PagedDataSource ps = new PagedDataSource();
        SqlConnection mycon = new SqlConnection(ConfigurationManager.AppSettings["ConSql"]);
        mycon.Open();
        string cmdtxt1 = "SELECT * FROM tb_LeaveWord";
        SqlDataAdapter MyAdapter = new SqlDataAdapter(cmdtxt1, mycon);
        DataSet ds = new DataSet();
        MyAdapter.Fill(ds, "tb_LeaveWord");
        ps.DataSource = ds.Tables["tb_LeaveWord"].DefaultView;
        ps.AllowPaging = true; //是否可以分页
        ps.PageSize = 3; //显示的数量
        ps.CurrentPageIndex = curpage - 1; //取得当前页的页码
        lnkbtnPrve.Enabled = true;
        lnkbtnTop.Enabled = true;
        lnkbtnNext.Enabled = true;
        lnkbtnLast.Enabled = true;
        if (curpage == 1)
        {
            lnkbtnTop.Enabled = false;//不显示第一页按钮
            lnkbtnPrve.Enabled = false;//不显示上一页按钮
        }
        if (curpage == ps.PageCount)
        {
            lnkbtnNext.Enabled = false;//不显示下一页
            lnkbtnLast.Enabled = false;//不显示最后一页

        }
        this.labCount.Text = Convert.ToString(ps.PageCount);
        this.DataList1.DataSource = ps;
        this.DataList1.DataKeyField = "ID";
        this.DataList1.DataBind();
    }

    protected void lnkbtnTop_Click(object sender, EventArgs e)
    {
        this.labNowPage.Text = "1";
        this.dlBind();
    }
    protected void lnkbtnPrve_Click(object sender, EventArgs e)
    {
        this.labNowPage.Text = Convert.ToString(Convert.ToInt32(this.labNowPage.Text) - 1);
        this.dlBind();
    }
    protected void lnkbtnNext_Click(object sender, EventArgs e)
    {
        this.labNowPage.Text = Convert.ToString(Convert.ToInt32(this.labNowPage.Text) + 1);
        this.dlBind();
    }
    protected void lnkbtnLast_Click(object sender, EventArgs e)
    {
        this.labNowPage.Text = this.labCount.Text;
        this.dlBind();
    }
    protected void lnkbtnFeedBack_Click(object sender, EventArgs e)
    {
        Response.Redirect("LeaveWordBack.aspx?ID="+Request["ID"].ToString()+"");
    }
    protected void DataList1_DeleteCommand(object source, DataListCommandEventArgs e)
    {
        string strid = this.DataList1.DataKeys[e.Item.ItemIndex].ToString(); //获取当前DataList控件列
        string com = "Delete from tb_LeaveWord where ID='" + Convert.ToInt32(strid) + "'";
        SqlData da = new SqlData();
        da.ExceSQL(com);
        Page.Response.Redirect("LeaveWordManage.aspx");
    }
}
