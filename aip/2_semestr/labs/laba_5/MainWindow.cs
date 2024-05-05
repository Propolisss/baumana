using System;
using Gtk;
using System.Collections.Generic;

public partial class MainWindow: Gtk.Window
{
	private double Determinant(int m1, int m2, List<List<double>> arr)
	{
		return (arr[0][m1] * arr[1][m2] - arr[1][m1] * arr[0][m2]);
	}

	private List<double> solve(double a, double b, double c, double d, double e, double f)
	{
		List<List<double>> kramer = new List<List<double>>();
		kramer.Add (new List<double>{ a, b, c });
		kramer.Add (new List<double>{ d, e, f });


		if (Determinant(0, 1, kramer) == 0)
		{
			return null;
		}
		else
		{
			return new List<double>{Determinant(2, 1, kramer) / Determinant(0, 1, kramer), Determinant(0, 2, kramer) / Determinant(0, 1, kramer)};
		}
	}

	public MainWindow () : base (Gtk.WindowType.Toplevel)
	{
		Build ();
		label1.Visible = false;
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}

	protected void OnButton2Clicked (object sender, EventArgs e)
	{
		try
		{
			List<double> solution = solve(double.Parse(entry_x1.Text), double.Parse(entry_y1.Text),
				double.Parse(entry_a.Text), double.Parse(entry_x2.Text),
				double.Parse(entry_y2.Text), double.Parse(entry_b.Text));
			if (solution != null) 
			{
				entry4.Text = solution[0].ToString();
				entry5.Text = solution[1].ToString();
				label1.Visible = false;
				entry4.Visible = true;
				entry5.Visible = true;
				label20.Visible = true;
				label21.Visible = true;
			} 
			else 
			{
				label1.Visible = true;
				entry4.Visible = false;
				entry5.Visible = false;
				label20.Visible = false;
				label21.Visible = false;
			}
		}
		catch 
		{
			MessageDialog md = new MessageDialog (null, DialogFlags.DestroyWithParent, MessageType.Error, 
				ButtonsType.Ok, "Ошибка: введены нечисловые данные. Пожалуйста, попробуйте ещё раз.");
			md.Run ();
			md.Destroy();

		}
	}
}
