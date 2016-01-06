<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="LeaveWordBack.aspx.cs" Inherits="Default3" Title="回复留言" %>
<%@ Register TagPrefix="FTB" Namespace="FreeTextBoxControls" Assembly="FreeTextBox" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<script language="javascript" type="text/javascript">
<!--

function Button1_onclick() {
history.go(-1);
}

// -->
</script>

    <table cellpadding="0" cellspacing="0"
        width="100%">
        <tr>
            <td colspan="3" rowspan="3">
    <table cellpadding="0" cellspacing="0">
        <tr>
            <td colspan="2" style="text-align: center; height: 64px;">
                <span style="font-size: 16pt"></span></td>
        </tr>
        <tr>
            <td style="width: 81px; text-align: center">
                <span style="font-size: 9pt">回复主题</span></td>
            <td colspan="1" style="text-align: left">
                <asp:TextBox ID="txtSubject" runat="server" Font-Size="9pt" MaxLength="50" ReadOnly="True"
                    Width="365px"></asp:TextBox></td>
        </tr>
        <tr>
            <td style="width: 81px; height: 21px; text-align: center">
                <span style="font-size: 9pt">回 复 人</span></td>
            <td style="width: 401px; height: 21px; text-align: left">
                <asp:TextBox ID="txtUid" runat="server" Font-Size="9pt" MaxLength="50"
                    Width="365px"></asp:TextBox><asp:RequiredFieldValidator ID="RequiredFieldValidator1"
                        runat="server" ControlToValidate="txtUid" ErrorMessage="姓名不能为空">*</asp:RequiredFieldValidator></td>
        </tr>
        <tr style="color: #505050">
            <td style="width: 81px; height: 1px; text-align: center">
                <span style="font-size: 9pt">回复内容</span></td>
            <td rowspan="2" style="width: 401px; text-align: left">
                <FTB:FreeTextBox id="FreeTextBox1" runat="Server" SupportFolder="aspnet_client/FreeTextBox/" ButtonSet="Office2003" Width="368px" Height="200px" ImageGalleryPath="images/" Language="zh-cn" />
            </td>
        </tr>
        <tr>
            <td style="width: 81px; height: 228px">
            </td>
        </tr>
        <tr>
            <td colspan="2" style="text-align: center">
                <asp:Button ID="btnOK" runat="server" Font-Size="9pt" OnClick="btnOK_Click" Text="提交" />
                <input id="Reset2" style="font-size: 9pt" type="reset" value="重置" />
                <input id="Button1" style="font-size: 9pt" type="button" value="返回" language="javascript" onclick="return Button1_onclick()" /><br />
                <asp:ValidationSummary ID="ValidationSummary1" runat="server" ShowMessageBox="True" ShowSummary="False" />
            </td>
        </tr>
    </table>
            </td>
        </tr>
        <tr>
        </tr>
        <tr>
        </tr>
    </table>
</asp:Content>

