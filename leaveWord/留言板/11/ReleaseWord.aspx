<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true"
    CodeFile="ReleaseWord.aspx.cs" Inherits="Default2" Title="留言板" %>

<%@ Register TagPrefix="FTB" Namespace="FreeTextBoxControls" Assembly="FreeTextBox" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">

    <script language="javascript" type="text/javascript">
<!--

function Reset2_onclick() {
history.go(-1);
}

// -->
    </script>

    <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
            <td width="538" height="29" align="left" valign="top" background="images/发表留言_04.jpg"
                class="dhwz">
                发表留言
            </td>
        </tr>
        <tr>
            <td align="left">
                <table style="width: 100%;">
                    <tr>
                        <td style="width: 87px">
                            留言主题：
                        </td>
                        <td style="width: 352px">
                            <asp:TextBox ID="TextBox1" runat="server" Width="360px"></asp:TextBox>
                        </td>
                        <td>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox1"
                                ErrorMessage="主题不能为空">*</asp:RequiredFieldValidator>
                        </td>
                    </tr>
                    <tr>
                        <td style="width: 87px">
                            留言内容：
                        </td>
                        <td style="width: 352px">
                            <FTB:FreeTextBox ID="FreeTextBox1" runat="Server" SupportFolder="aspnet_client/FreeTextBox/"
                                ButtonSet="Office2003" Height="200px" Width="420px" ImageGalleryPath="../../images/"
                                Language="zh-cn" />
                        </td>
                        <td>
                            &nbsp;
                        </td>
                    </tr>
                    <tr>
                        <td style="width: 87px">
                            &nbsp;
                        </td>
                        <td style="width: 352px" align="center">
                            <asp:Button ID="btnOK" runat="server" OnClick="btnOK_Click" Text="提交" 
                                Width="60px" />&nbsp;
                            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="重置" 
                                CausesValidation="False" Width="60px" />
                            &nbsp;
                            <input id="Reset2" type="reset" value="返回" language="javascript" 
                                onclick="return Reset2_onclick()" style="width: 60px" />
                        </td>
                        <td>
                            &nbsp;
                        </td>
                    </tr>
                    <tr>
                        <td style="width: 87px">
                            &nbsp;
                        </td>
                        <td style="width: 352px">
                            <asp:ValidationSummary ID="ValidationSummary1" runat="server" ShowMessageBox="True"
                                ShowSummary="False" />
                        </td>
                        <td>
                            &nbsp;
                        </td>
                    </tr>
                </table>
            </td>
        </tr>
    </table>
</asp:Content>
