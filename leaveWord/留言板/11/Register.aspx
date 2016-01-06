<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true"
    CodeFile="Register.aspx.cs" Inherits="Default2" Title="用户注册" %>

<%@ Register Src="UserControls/Register.ascx" TagName="Register" TagPrefix="uc1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
            <td width="538" height="29" align="left" valign="top" background="images/发表留言_04.jpg"
                class="dhwz">
                用户注册
            </td>
        </tr>
        <tr>
            <td align="left">
                <uc1:Register ID="Register2" runat="server" />
            </td>
        </tr>
    </table>
</asp:Content>
