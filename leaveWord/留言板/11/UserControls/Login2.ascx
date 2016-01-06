<%@ Control Language="C#" AutoEventWireup="true" CodeFile="Login2.ascx.cs" Inherits="UserControls_Login" %>
<table style="width: 300px">
    <tr>
        <td style="width: 80px; text-align: center">
            用户名</td>
        <td style="width: 138px">
            <asp:TextBox ID="txtUid" runat="server" Width="150px"></asp:TextBox></td>
        <td style="width: 48px">
            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="txtUid"
                ErrorMessage="用户名不能为空">*</asp:RequiredFieldValidator></td>
    </tr>
    <tr>
        <td style="text-align: center">
            密 &nbsp; 码</td>
        <td style="width: 138px">
            <asp:TextBox ID="txtPwd" runat="server" Width="150px" TextMode="Password"></asp:TextBox></td>
        <td style="width: 48px">
            <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="txtPwd"
                ErrorMessage="用户名不能为空">*</asp:RequiredFieldValidator></td>
    </tr>
    <tr>
        <td colspan="3" style="text-align: center">
            <asp:Button ID="btnOK" runat="server" Text="确定" OnClick="btnOK_Click" />
            <input id="Reset1" type="reset" value="取消" /></td>
    </tr>
    <tr>
        <td colspan="3" style="text-align: center">
            <asp:ValidationSummary ID="ValidationSummary1" runat="server" ShowMessageBox="True"
                ShowSummary="False" />
        </td>
    </tr>
</table>
