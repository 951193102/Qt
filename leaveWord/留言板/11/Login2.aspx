<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Login2.aspx.cs" Inherits="Default2" Title="登录管理" %>

<%@ Register Src="UserControls/Login2.ascx" TagName="Login2" TagPrefix="uc2" %>

<%@ Register Src="UserControls/Login.ascx" TagName="Login" TagPrefix="uc1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
            <td width="538" height="29" align="left" valign="top" background="images/发表留言_04.jpg"
                class="dhwz">
                登录
            </td>
        </tr>
        <tr>
            <td align="left">
                <table width="100%" height="400" style="cellpadding="0" cellspacing="0">
        <tr>
            <td>
            </td>
            <td style="width: 271px">
                &nbsp;<uc2:Login2 ID="Login2_1" runat="server" />
            </td>
            <td>
            </td>
        </tr>
        <tr>
            <td style="height: 19px">
            </td>
            <td style="width: 271px; height: 19px;">
            </td>
            <td style="height: 19px">
            </td>
        </tr>
    </table>
            </td>
        </tr>
    </table>
    
</asp:Content>

