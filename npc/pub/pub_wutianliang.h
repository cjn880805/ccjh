//wutianliang.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_wutianliang);

virtual void create()
{
	set_name("������","wutianliang");

	set("icon", general);
	set("title", "�ɶ��ᶽ");

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long","����������ԭ��ֻ��һ���ν����ԴӸ����ɱ��С�����󣬾�Ȼ���˺�ͨ��������Ϊ�ܱ������ܳ���ȫ��֮����");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	carry_object("dadao2")->wield();
	carry_object("jjunfu")->wear();
	carry_object("parry_book")->wear();
	add_money(1000);
	set("no_huan",1);

};

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("����һ��������û�����");
	
	if ( EQUALSTR(ob->querystr("id"), "gongting mifang") && EQUALSTR(ob->querystr("name"), "��͢�ط�") )
	{
		if(me->query("zhang/renwu5")==2 && me->query_temp("zhang/renwu5_210") 
			&& !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_21"))
		{
			tell_object(me,"\n$HIC���������׵����Ŵ��˶�Ȯ��������֮�£���������ٵ����Ŵ��ˣ�����ذɣ�\n");
			if(!me->query_temp("zhang/renwu5_21"))
				me->set_temp("zhang/renwu5_21",1);
			destruct(ob);
			me->delete_temp("zhang/renwu5_210");
			if(me->query_temp("zhang/renwu5_21") && me->query_temp("zhang/renwu5_22")
				&& me->query_temp("zhang/renwu5_23") && me->query_temp("zhang/renwu5_24"))
			{
				me->set("zhang/renwu5_ok",2);
				me->delete_temp("zhang/renwu5_21");
				me->delete_temp("zhang/renwu5_22");
				me->delete_temp("zhang/renwu5_23");
				me->delete_temp("zhang/renwu5_24");
			}
			return 1;
		}
	}
	return 0;
}
NPC_END;
