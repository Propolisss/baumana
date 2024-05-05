using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;

namespace practice_4
{
    internal class DataBase : DbContext
    {
        public DbSet<Shoe> Shoes { get; set; }

        public DataBase() : base("DefaultConnection") { }
    }
}
