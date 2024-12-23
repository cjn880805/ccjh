// shenjian_wu6.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;

NPC_BEGIN(CNshenjian_wu6);

virtual void create()
{
	set_name("ÎâÁù", "wu liupo");
	set("title",  "Éñ¼ý°ËÐÛ" );
	set("gender", "ÄÐÐÔ");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
 	set("icon",young_man4);
	
	set("max_hp", 1500);
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 30000+random(10000));
	
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("throwing", 80);
	set_skill("xuanyuan_arrow", 80);
	set_skill("changquan", 80);
	set_skill("lingxu_bu", 80);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "changquan");
	map_skill("throwing", "xuanyuan_arrow");
	map_skill("unarmed", "changquan");
	
	set_temp("is_riding", "Ó³ÑªÂí");
	
	carry_object("arrow")->wield();
	carry_object("cloth")->wear();
	add_money(1000);
}
/*
virtual void init(CChar *me)
{	
object ob;

  CNpc::init(me);
  if( userp(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
		}
		}
		virtual char * greeting(CChar * ob)
		{
        object obj;
        if( (obj = present("zhao min", ob->environment())) )
        {
		this_object()->set_leader(obj);
        }
		}
*/
NPC_END;