//hutaseng1.h
//code by zwb
//12-16

NPC_BEGIN(CNDaLi_hutaseng1);

virtual void create()
{
	set_name("����ɮ","hu ta seng");

	set("gender", "����" );
	set("class", "bonze");
	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_monk);

	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 20);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("tiannan_step", 80);
	set_skill("kurong_changong", 70);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");

	set_inquiry("������","����������֮����ԭ��������������ʩ������ȥ�����𣿡�");
	set_inquiry("����","��ʩ��Ҳ��֪�����ǵ�������������ѵ�����˼��˼һ�£���");

	carry_object("gangzhang")->wield();
	set("no_huan",1);
};

virtual int accept_object(CChar * me ,CContainer * ob)
{
	if(EQUALSTR(ob->querystr("base_name"), "coin"))
	{
		if(ob->query("value")>=1000)
		{
			add_money(ob->query("value"));
			message_vision("$n���ĵذ�$N������������",me);
			me->move(load_room("����������"));
			destruct(ob);
			return 1;
		}
		else
		{
			message_vision("$n˫�ֺ�ʮ������$N�����������������ӷ𣡡�", me, this);
			return 1;
		}
	}
	return 0;
}


NPC_END;
