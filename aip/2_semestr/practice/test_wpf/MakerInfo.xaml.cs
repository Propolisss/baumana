using practice_4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace test_wpf
{
    /// <summary>
    /// Логика взаимодействия для MakerInfo.xaml
    /// </summary>
    public partial class MakerInfo : Window
    {
        private string maker;
        public MakerInfo(string maker = null)
        {
            InitializeComponent();
            this.maker = maker;
            List<Shoe> shoes = MainWindow.dataBase.Shoes.ToList();
            foreach (Shoe shoe in shoes)
            {
                if (shoe.Maker == maker)
                    AddShoeToListView(shoe);
            }

        }

        public void AddShoeToListView(Shoe shoe)
        {
            ListViewItem listViewItem = new ListViewItem();
            listViewItem.IsEnabled = false;
            Grid grid = new Grid();
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });

            TextBlock textBlock1 = new TextBlock { Text = shoe.Model, Margin = new Thickness(5) };
            Grid.SetColumn(textBlock1, 0);
            grid.Children.Add(textBlock1);

            TextBlock textBlock2 = new TextBlock { Text = shoe.Maker, Margin = new Thickness(5) };
            Grid.SetColumn(textBlock2, 1);
            grid.Children.Add(textBlock2);

            TextBlock textBlock3 = new TextBlock { Text = shoe.Size.ToString(), Margin = new Thickness(5) };
            Grid.SetColumn(textBlock3, 2);
            grid.Children.Add(textBlock3);

            TextBlock textBlock4 = new TextBlock { Text = shoe.Amount.ToString(), Margin = new Thickness(5) };
            Grid.SetColumn(textBlock4, 3);
            grid.Children.Add(textBlock4);

            listViewItem.Content = grid;

            ShoesItems.Items.Add(listViewItem);
        }
    }
}
