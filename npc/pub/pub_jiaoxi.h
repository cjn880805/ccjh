// pub_jiaoxi.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

NPC_BEGIN(CNpub_jiaoxi);

virtual void create()
{
	set_name("�Ϸ���",  "lao jiaoxi" );

	set("icon", old_man2);
	set("long","һ��Ψ����ͼ�������Ͻ�ϰ����������īˮ�����㻹Ҫ��Ǯ��");
	set("gender", "����");
	set("age", 65);
	set_skill("literate", 200);
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	set("combat_exp", 40000);
	set("shen_type", 1);
	set_inquiry("��" , "��!�鵽��ʱ�����١�");
	set_inquiry("����" , "�裿�㲻���ҵ��������㣿��!");
	set("no_huan",1);
	
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/��2", -1);
	if (! me->query_temp("mark/��2"))
	{
		DownLoad(me);
		return 1;
	}

	return 0;
}

int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("mark/��2"))
		return 0;
	
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (! who->query_temp("mark/��2")) 
		who->set_temp("mark/��2", 0l);
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 500)
	{
		message_vision("�Ϸ���ͬ��ָ��$NһЩ����д�ֵ����⡣", who);
		who->add_temp("mark/��2", ob->query("value") / 250);
		DownLoad(who);
	}
	destruct(ob);
	return 1;
}

NPC_END;