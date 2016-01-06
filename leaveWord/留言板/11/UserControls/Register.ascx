<%@ Control Language="C#" AutoEventWireup="true" CodeFile="Register.ascx.cs" Inherits="UserControls_Register" %>
<table width="100%" style="height: 1px">
    <tr>
        <td colspan="3" rowspan="3" style="height: 138px">
            <asp:MultiView ID="MultiView1" runat="server" ActiveViewIndex="0">
                <asp:View ID="View1" runat="server">
                    <table width="100%" cellpadding="0" cellspacing="0" style="height: 13px">
                        <tr>
                            <td colspan="3" rowspan="2" style="text-align: center">
                            <iframe src="UserControls/notice.htm" scrolling=auto noresize width="320" style="width: 470px; height: 266px"></iframe>
                            </td>
                        </tr>
                        <tr>
                        </tr>
                        <tr>
                            <td colspan="3" style="text-align: center">
                                <asp:Button ID="btnOK" runat="server" Text="同意" OnClick="btnOK_Click" />
                                <asp:Button ID="btnNoOK" runat="server" Text="不同意" OnClick="btnNoOK_Click" /></td>
                        </tr>
                    </table>
                </asp:View>
                <asp:View ID="View2" runat="server">
                    <table width="100%" cellpadding="0" cellspacing="0" style="height: 4px">
                        <tr>
                            <td colspan="3" rowspan="3" style="text-align: center">
                                <table cellpadding="0" cellspacing="0" style="height: 52px; text-align: center; width: 311px;">
                                    <tr>
                                        <td style="width: 80px; height: 10px">
                                            用户名</td>
                                        <td style="width: 136px; height: 10px; text-align: left;">
                                            <asp:TextBox ID="txtUid" runat="server" Width="134px"></asp:TextBox></td>
                                        <td style="width: 102px; height: 10px; text-align: left;">
                                            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="用户名不能为空"
                                                Font-Size="9pt" ControlToValidate="txtUid">用户名不能为空</asp:RequiredFieldValidator></td>
                                    </tr>
                                    <tr>
                                        <td>
                                            密码</td>
                                        <td style="width: 136px; text-align: left;">
                                            <asp:TextBox ID="txtPwd" runat="server" Width="134px" MaxLength="20" TextMode="Password"></asp:TextBox></td>
                                        <td style="width: 102px; text-align: left">
                                            <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="密码不能为空"
                                                Font-Size="9pt" ControlToValidate="txtPwd">密码不能为空</asp:RequiredFieldValidator></td>
                                    </tr>
                                    <tr>
                                        <td style="height: 5px">
                                            确认密码</td>
                                        <td style="width: 136px; height: 5px; text-align: left;">
                                            <asp:TextBox ID="txtOkPwd" runat="server" Width="134px" MaxLength="20" TextMode="Password"></asp:TextBox></td>
                                        <td style="height: 5px; width: 102px; text-align: left;">
                                            <asp:CompareValidator ID="CompareValidator1" runat="server" ErrorMessage="CompareValidator"
                                                Font-Size="9pt" ControlToCompare="txtPwd" ControlToValidate="txtOkPwd">密码不一致</asp:CompareValidator></td>
                                    </tr>
                                    <tr>
                                        <td style="height: 5px">
                                            性别</td>
                                        <td style="width: 136px; height: 5px; text-align: left;">
                                            <asp:RadioButtonList ID="radSex" runat="server" RepeatDirection="Horizontal">
                                                <asp:ListItem Selected="True">男</asp:ListItem>
                                                <asp:ListItem>女</asp:ListItem>
                                            </asp:RadioButtonList></td>
                                        <td style="height: 5px; width: 102px; text-align: left;">
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="height: 5px">
                                            主页</td>
                                        <td style="width: 136px; height: 5px; text-align: left;">
                                            <asp:TextBox ID="txtWebSite" runat="server" MaxLength="50" Width="134px">http://</asp:TextBox></td>
                                        <td style="height: 5px; width: 102px; text-align: left;">
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="height: 5px">
                                            Email</td>
                                        <td style="width: 136px; height: 5px; text-align: left;">
                                            <asp:TextBox ID="txtEmail" runat="server" MaxLength="30" Width="134px"></asp:TextBox></td>
                                        <td style="height: 5px; width: 102px; text-align: left;">
                                        </td>
                                    </tr>
                                    <tr>
                                        <td style="height: 5px">
                                            QQ</td>
                                        <td style="width: 136px; height: 5px; text-align: left">
                                            <asp:TextBox ID="txtQQ" runat="server" MaxLength="20" Width="134px"></asp:TextBox></td>
                                        <td style="width: 102px; height: 5px; text-align: left">
                                        </td>
                                    </tr>
                                    <tr>
                                        <td colspan="3" style="height: 5px">
                                            <asp:Button ID="btnOK1" runat="server" Text="提交" OnClick="btnOK1_Click" />
                                            <input id="Reset1" type="reset" value="重置" /></td>
                                    </tr>
                                </table>
                            </td>
                        </tr>
                        <tr>
                        </tr>
                        <tr>
                        </tr>
                    </table>
                </asp:View>
            </asp:MultiView></td>
    </tr>
    <tr>
    </tr>
    <tr>
    </tr>
</table>
