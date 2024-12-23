//xy_limuou.h	����ذ��ѡ���ľż
//�ز� 2002��12��2

NPC_BEGIN(CNxy_limuou);

void create()
{
	set_name("��ľż","li muou");
	set("gender", "����");
	set("age", 27);
	set("long","�����������Ͳʻ������ף�����ȥ����������췢���룬��״����֮����ֱ�Ǹ����֣����ϻ�����һ�����������Ľ��ۡ�");

	set("attitude", "peaceful");
	set("icon",young_man2);

	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 40);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("hand", 50);
	set_skill("lingboweibu", 50);
	set_skill("beiming_shengong",50);
	set_skill("liuyang_zhang", 50);
	set_skill("zhemei_shou", 50);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");
	
	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","Ϸ��");
	set("no_talk",1);
	set("no_huan",1);

};

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting()) 
		tell_object(me,"\n��ľż������˵���������츳��������������ż�񣬱�����Ϸ��ƾʲô�ͱ��Һ��أ���\n");
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "����") && EQUALSTR(ob->querystr("id"), "cuiyu")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_65") && !who->query_temp("xy/renwu1_650")  )
	{
		destruct(ob);
		tell_object(who,"\n��ľż����ز���һ������");
		tell_object(who,"��ľż���Ե��£��е������������������Ҳ��������ɽ����Ϸ���ȣ���ˣ����ˣ����");
		tell_object(who,"��ľż����˫�ۣ�����ָ��ָ���㣬�ϳ�����������������~~~~��Ҫ��~~~~~�ʹͣ���\n");
		who->set_temp("xy/renwu1_650",1);//����ľż����
		return 1;
	}
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_650") && !me->query_temp("xy/renwu1_65"))
		{
			AddMenuItem("ת����ľż������Ϧ���֮��","qixi",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61")&& me->query_temp("xy/renwu1_650") )
		{
			if(!me->query_temp("xy/renwu1_65") )
				me->set_temp("xy/renwu1_65",1);//֪ͨ��ľż�μ���Ϧ���
			say("��ľżһԾ���𣺡�ĩ��~~����~����Ϧ֮�ڣ���~ʦ~��~~ң~�֣�Ǻ~~Ǻ~~Ǻ......��",me);
		}
		else
			say("��ľż������˵���������츳��������������ż�񣬱�����Ϸ��ƾʲô�ͱ��Һ��أ���",me);
		SendMenu(me);
		return 1;
	}
	else
	{
		say("��ľż������˵���������츳��������������ż�񣬱�����Ϸ��ƾʲô�ͱ��Һ��أ���",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




