NPC_BEGIN(CNPub_flowerg);

virtual void create()
{
	set_name("��������","flowerg");
	
	set("icon", young_woman6);
	set("gender", "Ů��" );
	set("age", 18);
	set("long", "һ����ò������С���");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_hp", 300);
	set("mp", 100);
	set("max_mp", 100);
	set("score", 1000);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	carry_object("xiaoao")->wear();
	carry_object("wuming")->wear();
	carry_object("honghua")->wear();
	carry_object("duanchang")->wear();
	
	add_money(10);
	set("no_huan",1);
};

virtual char * greeting(CChar * me)
{
	char msg[255];
	return snprintf(msg, 255, "��������˵������λ%s����һ�仨�ɡ�", query_respect(me) );
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("wei/renwu1") && me->query_temp("wei/renwu5_10") && !me->query_temp("wei/renwu5_13"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("ѯ�ʶϳ���������","duanchuang",me);
			SendMenu(me);
			return 1;
		}
		else if(!strcmp(ask, "duanchuang") )
		{
			tell_object(me,"$HIC������������ҡ��ҡͷ��");
			tell_object(me,"�����������ĵ�̾��һ������������ĺù¶�����˭���ں�������һ��СŮ�ˣ���\n");
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}


virtual int accept_object(CChar * me, CContainer * ob)
{
	if(! ob->is_character() ) return 0;
	if(me->query("wei/renwu1") && me->query_temp("wei/renwu5_10") && !me->query_temp("wei/renwu5_13"))
	{
		if ( userp(ob) )
		{	
			say("�������ﾪ�ȵĽ���һ�����⡭���ҿɲ���Ҫ����", me);
			SendMenu(me);
			return 0;
		}
		if ( DIFFERSTR(ob->querystr("gender"), "����"))
		{	
			say("�������ﾪ�ȵĽ���һ�����⡭���ҿɲ���Ҫ����", me);
			SendMenu(me);
			return 0;
		}
		if ( ob->query("age") <16 )
		{	
			say("��������΢΢��ü������������û�����ء�", me); 
			SendMenu(me);
			return 0;
		}
		if ( ob->query("age") >50 )
		{	 
			say("������������һ�ڵ��������Ϲ�ͷ������Ҫ����ʲô��", me);
			SendMenu(me);
			return 0;
		}
		if ( ob->query("per") <22 )
		{	 
			say("��������˵�����⡭��Ҳ̫�ѿ��˵㡭��", me);
			SendMenu(me);
			return 0;
		}
		tell_object(me,"\n$HIC��������ѽ�ؾ�̾��һ����");
		tell_object(me,"$HIC��������˵������Ӣ����С���ӣ�����ϲ������");
		tell_object(me,"$HIC�������������ʾ���Եĸ�л��");
		tell_object(me,"�������ｻ��������1�Ķϳ�����");
		load_item("duanchang")->move(me);
		me->set_temp("wei/renwu5_13",1);//ȡ�öϳ���
		return 1;
	}
	return 0;
}

NPC_END;
