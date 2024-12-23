// pub_laoxiansheng.c ������
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_laoxiansheng);

virtual void create()
{
	set_name("������", "lao xiansheng");

	set("icon", pawnshop_boss);
	set("long","��λ���������й�״Ԫ��������٣��������ϻ��ϼ������������꣬������ʹ���ĵµ��������룬�����Ϊ����ǽ��Ρ�");
    set("gender", "����");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 300);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 10);
	set("combat_exp", 4000);
	set("shen_type", 1);
	set("no_huan",1);

}

virtual int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("mark/��"))
		return 0;

	return 1;
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;
	if(! me->query_temp("mark/��")) return 1;

	me->add_temp("mark/��", -1);
	if(! me->query_temp("mark/��"))
	{
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

virtual int accept_object(CChar * me, CContainer * ob)
{	
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000)
	{
		message_vision("������ͬ��ָ��$NһЩ����д�ֵ����⡣", me);
		me->set_temp("mark/��", ob->query("value") / 200);
		DownLoad(me);
		if( me->query_skill("literate", 1) > 21)
		{
			tell_object(me,"����������һ�����Ļ�֪ʶ��Ҳ�����Լ����������ˡ�");
		}
	}
	destruct(ob);
	return 1;
}

NPC_END;