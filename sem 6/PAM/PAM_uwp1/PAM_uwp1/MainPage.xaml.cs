using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace PAM_uwp1
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        String currency = "";

        public MainPage()
        {
            this.InitializeComponent();
           
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            String input = this.editTextInput.Text;
            String output = "";
            Double value = 0.0;
            if (this.currency.Equals(""))
            {
                output = "Error - select curreny.";
            } else if (this.currency.Equals("EUR"))
            {
                value = Double.Parse(input) * 4.33;
            }else if (this.currency.Equals("USD"))
            {
                value = Double.Parse(input) * 3.75;
            }

            this.outputBox.Text = value.ToString();
        }

        private void TextBlock_SelectionChanged(object sender, RoutedEventArgs e)
        {

        }

        private void ListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void RadioButton_Checked(object sender, RoutedEventArgs e)
        {
            this.currency = "USD";
            this.outputBox.Text = this.currency;
        }

        private void RadioButton_Checked_1(object sender, RoutedEventArgs e)
        {
            this.currency = "EUR";
            this.outputBox.Text = this.currency;
        }
    }
}
