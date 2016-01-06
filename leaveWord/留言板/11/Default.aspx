<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true"
    CodeFile="Default.aspx.cs" Inherits="Default2" Title="首页" %>

<%@ Register Src="UserControls/ShowSubject.ascx" TagName="ShowSubject" TagPrefix="uc2" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
            <td width="538" height="29" align="left" valign="top" background="images/发表留言_04.jpg"
                class="dhwz">
                查看留言
            </td>
        </tr>
        <tr>
            <td align="left">
                <uc2:ShowSubject ID="ShowSubject1" runat="server" />
            </td>
        </tr>
    </table>
</asp:Content>