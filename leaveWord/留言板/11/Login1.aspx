<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true"
    CodeFile="Login1.aspx.cs" Inherits="Default2" Title="登录管理" %>

<%@ Register Src="UserControls/Login1.ascx" TagName="Login1" TagPrefix="uc2" %>
<%@ Register Src="UserControls/Login.ascx" TagName="Login" TagPrefix="uc1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    
    
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
                    <tr>
                        <td width="538" height="29" align="left" valign="top" background="images/发表留言_04.jpg"
                            class="dhwz">
                            用户登录
                        </td>
                    </tr>
                    <tr>
                        <td align="center">
                            
                            <br />
                            
                          <uc2:Login1 ID="Login1_1" runat="server" />
                            
                        </td>
                    </tr>
                </table>
    
    
</asp:Content>
