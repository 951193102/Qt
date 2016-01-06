<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" Title="无标题页" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

   <table  background="Images/发表留言_04.jpg"  valign="top">
    <tr >
  <td width="538" height="54" align="center"    >
            查看留言  
            </td>
           
    </tr>
   </table>
   
    <table width="100%" >
    <tr>
    <td colspan="3" rowspan="3"></td>
    </tr>
    <tr></tr>
    <tr></tr>
    <tr>
    <td colspan="3" rowspan="1"  align="left" >
    <%=GetList()%>
    </td>
    </tr>
    </table>
</asp:Content>

