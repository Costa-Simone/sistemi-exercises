using AppCassa.Classi;
using Ex02_Socket_Tris.Classi;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarShopLibrary
{
    public class DbTools
    {
        public List<Tavolo> listaTavoli = new List<Tavolo>();
        public List<Piatto> listaPiatti = new List<Piatto>();
        public List<Ordine> listaOrdini = new List<Ordine>();
        public List<Categoria> listaCategorie = new List<Categoria>();
        public List<Scontrino> listaScontrini = new List<Scontrino>();

        public ClsUDPServer clsServer;
        public ClsMessagge clsMsg;
        public ClasUDPClient clientCucina, clientMobile;

        string connStr;

        public DbTools()
        {
            connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\valbo\Documents\GitHub\sistemi-exercises\QUARTA\Vacanze\AppCassa\CassaDB.mdf;Integrated Security=True;Connect Timeout=30";
        }

        public void CaricaTavoli()
        {
            List<Tavolo> tavoli = new List<Tavolo>();

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                String sql = "select * from Tavoli";

                using (SqlCommand command = new SqlCommand(sql, conn))
                {
                    conn.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int idTavolo = Convert.ToInt32(reader["IdTavolo"]);
                            int numero = Convert.ToInt32(reader["Numero"]);
                            int occupato = Convert.ToInt32(reader["Occupato"]);

                            Tavolo t = new Tavolo(idTavolo, numero, occupato);
                            tavoli.Add(t);
                        }
                    }
                }
            }

            listaTavoli = tavoli;
        }
        public void CaricaScontrini()
        {
            List<Scontrino> scontrini = new List<Scontrino>();

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                String sql = "select * from Scontrini";

                using (SqlCommand command = new SqlCommand(sql, conn))
                {
                    conn.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int idScontrino = Convert.ToInt32(reader["IdScontrino"]);
                            int idOrdine = Convert.ToInt32(reader["IDOrdine"]);
                            int importo = Convert.ToInt32(reader["Importo"]);
                            DateTime dataEmissione = DateTime.Parse(reader["DataEmissione"].ToString());

                            Scontrino s = new Scontrino(idScontrino, idOrdine, importo, dataEmissione);
                            scontrini.Add(s);
                        }
                    }
                }
            }

            listaScontrini = scontrini;
        }
        public void CaricaCategorie()
        {
            List<Categoria> categorie = new List<Categoria>();

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                String sql = "select * from Categorie";

                using (SqlCommand command = new SqlCommand(sql, conn))
                {
                    conn.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int idCategoria = Convert.ToInt32(reader["IdCat"]);
                            string descr = reader["Descr"].ToString();

                            Categoria c = new Categoria(idCategoria, descr);
                            categorie.Add(c);
                        }
                    }
                }
            }

            listaCategorie = categorie;
        }
        public void CaricaPiatti()
        {
            List<Piatto> piatti = new List<Piatto>();

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                String sql = "select * from Piatti";

                using (SqlCommand command = new SqlCommand(sql, conn))
                {
                    conn.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int idPiatto = Convert.ToInt32(reader["IdPiatto"]);
                            int idCategoria = Convert.ToInt32(reader["IdCat"]);
                            string descr = reader["Descr"].ToString();
                            int importo = Convert.ToInt32(reader["Importo"]);

                            Piatto p = new Piatto(idPiatto, idCategoria, descr, importo);
                            piatti.Add(p);
                        }
                    }
                }
            }

            listaPiatti = piatti;
        }
        public void CaricaOrdini()
        {
            List<Ordine> ordini = new List<Ordine>();

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                String sql = "select * from Ordini";

                using (SqlCommand command = new SqlCommand(sql, conn))
                {
                    conn.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int idOrdine = Convert.ToInt32(reader["IdOrdine"]);
                            int idTavolo = Convert.ToInt32(reader["IdTavolo"]);
                            int idPiatto = Convert.ToInt32(reader["IdPiatto"]);
                            int idUtente = Convert.ToInt32(reader["IdUtente"]);

                            Ordine o = new Ordine(idOrdine, idTavolo, idPiatto, idUtente);
                            ordini.Add(o);
                        }
                    }
                }
            }

            listaOrdini = ordini;
        }
        public void CreaScontrino(Ordine o, int importo)
        {
            using (SqlConnection connection = new SqlConnection(connStr))
            {
                connection.Open();

                string insertQuery = $"INSERT INTO Scontrini (IdOrdine, Importo, DataEmissione) VALUES ({o.IdOrdine}, {importo}, '{DateTime.Now}')";

                using (SqlCommand command = new SqlCommand(insertQuery, connection))
                {
                    int rowsAffected = command.ExecuteNonQuery();
                }
            }
        }
    }
}