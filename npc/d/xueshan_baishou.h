// xueshan_baishou.c ������

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_baishou);

virtual void create()
{
	set_name("����ң", "bai zizai");
	set("nickname", "ѩɽ����������");
	set("title", "����Ƕ�");
	set("long","������ѩɽ�ɷ�֧ѩɽ���ɵ������ˣ�����Ϊ�����书��һ�� ����Լ��ʮ���꣬�����ܸɣ�������������һ𣬽����Դ� ");
	set("gender", "����");
	set("age", 55);
        set("icon",old_man2);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 6000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 125000);
	set("score", 60000);
	
	set_skill("force", 100);
	set_skill("hand", 170);
	set_skill("dodge", 100);
	set_skill("staff", 170);
	set_skill("unarmed", 100);
	set_skill("hamagong", 200);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("chanchu_bufa", 150);
	set_skill("shexing_diaoshou", 100);
	set_skill("literate", 80);
	set_skill("lingshe_zhangfa", 150);
	
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("staff", "lingshe_zhangfa");
	
	carry_object("gangzhang")->wield();
	carry_object("white_robe")->wear();
	add_money(2000);
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;
	int i ;
	if (userp(ob)
		&& !(ob->environment())->query("no_fight"))
	{
		if (ob->query("repute")>0)
		{
			say(" �����������������");
			say(" �в�֪�ң��Ҷ�֪�ˣ�Ӣ�������޵иǳ��ڴˡ�");
			say(" ����磬�����֣�������𣬲�����ɽ���˱��Һͽ���֮����");
			
			obj = all_inventory(me->environment());
			for(i=0; i<sizeof(obj); i++)
			{
				if(obj[i]==me)
					continue;
				if (random(ob->query("kar"))>28)
				{
					say(" ���ܵ��ˣ���Ϊ������Ե��������������������ȥ�ɡ� ");
					obn = load_item("/d/xiakedao/obj/shane-bu");
					obn->move(ob);
					say(" �����͵����������ѧ�书�ɣ���������һ��֮���� ");
					ob->move("/d/xiakedao/neiting");
					tell_object(ob,"��ֻ����ǰһ�ڣ�ʲôҲ��֪���ˣ�����ȴ���صĳ�����һ�������ڡ� ");
				}
				say(" ���ܵ��ˣ���Ϊ��Ե���ں���һ�ѽ�������Ե������ȥ�ɡ� ");
			}
		}
		else
		{
			say(" ������Ӧ������·����ȥ�ɡ�");
		}
	}
}
*/
NPC_END;