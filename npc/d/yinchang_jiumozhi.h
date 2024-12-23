// yinchang_jiumozhi.c �Ħ��

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_jiumozhi);

virtual void create()
{
	set_name("�Ħ��", "jiumo zhi");
	set("nickname",  "��������" );
	set("long","������ѩɽ�µ����ţ��˳ƴ����������Ħ�㡣���Է��о�����о�����һ��������ģ�ͷ��ɮñ��");
	set("title","ѩɽ������");
	set("gender", "����");
	set("age", 60);
        set("icon",old_man1);

	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 200);
	set_skill("xiaowuxiang", 200);
	set_skill("dodge", 200);
	set_skill("shenkong_xing", 150);
	set_skill("unarmed", 200);
	set_skill("yujiamu_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("mingwang_jian", 200);
	set_skill("mizong_xinfa", 200);
	set_skill("literate", 100);
	set_skill("staff", 100);
	set_skill("xiangmo_chu", 100 );
	set_skill("strike", 200 );
	set_skill("huoyan_dao", 200);
	
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "mingwang_jian");
	map_skill("sword", "mingwang_jian");
	map_skill("staff", "xiangmo_chu");
	map_skill("strike","huoyan_dao");
	
	prepare_skill("strike","huoyan_dao");
	
	create_family("ѩɽ��", 1, "����");
	set("class", "bonze");
	
	carry_object("r_jiasha")->wear();
	carry_object("sengmao")->wear();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;
	int i;
	
	obj = all_inventory(me->environment());
	say(" �Կ��Ϻ�ӧ����ӧ������Ӧ���������ģ����Ƿ�ָ����֮�ƣ�");
	command("consider");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="xuedao-laozu")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;