<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="fabiaoliuyan.aspx.cs" Inherits="fabiaoliuyan" Title="无标题页" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

 <table  background="Images/发表留言_04.jpg"  valign="top">
    <tr >
  <td width="538" height="54" align="center"    >
            发表留言  
            </td>
           
    </tr>
   </table>
   <div  align="center">
    <asp:Label ID="Label1" runat="server" Text="Label">留言主题:</asp:Label>  <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br /><br />
       <asp:Label ID="Label2" runat="server" Text="Label">留言类容:</asp:Label><asp:TextBox ID="TextBox2"  runat="server" TextMode="MultiLine" Rows="5" ForeColor="Fuchsia" Font-Strikeout="False" BackColor="#CCFFFF"></asp:TextBox>
    
</div>
   


</asp:Content>

   
