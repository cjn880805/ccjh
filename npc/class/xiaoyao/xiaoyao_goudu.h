// xiaoyao_goudu.c

//code by Fisho
//date:2000-12-22

/*
Edit by wolfman 2001-6-28
���������޷���ȡ�����⣬ֻ����һ��
*/

NPC_BEGIN(CNxiaoyao_goudu);

virtual void create()
{
	set_name("������",  "gou du");
	set("long", "������ȥҲ�Ǽ�ʮ������ˣ�ȴ�Ǵ�Ȼһ������ӵ�ģ���� ");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);
 	set("icon",old_man1);
	
	set("max_hp", 2400);
	set("mp", 800);
	set("max_mp", 800);
	set("mp_factor", 60);
	set("combat_exp", 150000);
	set("score", 40000);
	
	set_skill("blade",60);
	set_skill("xiaoyao_dao",60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("lingboweibu", 60);
	set_skill("beiming_shengong",60);
	set_skill("zhemei_shou", 60);
	
	map_skill("unarmed", "zhemei_shou");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("blade", "xiaoyao_dao");
	
	set("book_count", 1);
	
	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","���");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();		//blade modified to gangdao, lanwood 2000-12-30
	set("no_talk",1);
	set("no_huan",1);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_64")) 
	{
		tell_object(me,"\n���Ҽ��������ʵ�������ͬ��֮�ԣ����������������������֣������ν��ͣ���\n");
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "���׾�ϵ��ƪ��") && EQUALSTR(ob->querystr("skill/name"), "qimen_wuxing")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_64") && !who->query_temp("xy/renwu1_640") )
	{
		destruct(ob);
		tell_object(who,"\n��Կ��Ҽ�˵�����������׾�ϵ��ƪ���Դǣ�����Ϊ�����˼�������������һ���о��Ļ����Ȿϵ��ƪ������ɡ���\n");
		who->set_temp("xy/renwu1_640",1);//�����Ҽ�һ���׾�ϵ��ƪ
		return 1;
	}
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("����Ҽ���̹������������", "lunyu",me);	
		AddMenuItem("����Ҽ���̹��ڵ��е����ܵ�����", "jingling",me);

		if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_640") && !me->query_temp("xy/renwu1_64"))
		{
			AddMenuItem("ת����Ҽ�������Ϧ���֮��","qixi",me);
		}
		SendMenu(me);
	}
	else if(!strcmp(ask, "lunyu") )
	{
		CContainer *obj;
		CContainer * r = load_room("��ң��С��2");
		
		if(EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv") && (r->query_temp("no_book")==1))
		{
			r->add_temp("no_book",-1);
			say("ʦ����Ҫ���������ȥ���ǡ�",me);
			message_vision("�����Ѵӻ����ͳ�һ�����飬���˸�$N�� ",me);
			obj=load_item("literateb4");//����
			obj->move(me);
			say("�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ� ", me);
			SendMenu(me);
			return 1;
		}
		else if (query("book_count") < 1)
		{
			say( "�������ˣ��Ǳ���������Ѿ����͸������ˡ�",me); 
			SendMenu(me);
			return 1;
		}
		else
		{
			add("book_count", -1);                  
			say("�������������û���ˣ����ﻹ�����ɸ��ִ������������顣���鲻����͵", me);
			say("��Ȼ����ô��ѧ���ҾͰ����͸���ɡ� ", me);
			message_vision("�����ѷ��䵹�����˰��죬�ҳ�һ�����飬���˸�$N��",me);
			
			if (random(2) == 1) 
				obj=load_item("strike_book");//�Ʒ�����
			else 
				obj=load_item("book_paper");//�׽��ѧƪ
			obj->move(me);
			
			say("����������д������֪�����֣� ", me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		{
			say("�㲻��������ң�ɵ����ˣ�������Щ��ʲô��",me);
		}
		else if(me->query_temp("xiaoyao/����")==3)
		{
			me->add_temp("xiaoyao/����",1);
			say("����ң�����е����ܣ���˵��ʦ������ʱ��һ�θ�������йء���������ôԵ�ʣ�Ҳ��ֻ��ʦ��֪����",me);
		}
		else
		{
			me->delete_temp("xiaoyao/����");
			say( "ʦ�治��������ʹ�á���ң�����еľ��У���Ϊ���ӣ������Ե����ز��ǡ�",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61")&& me->query_temp("xy/renwu1_640") )
		{
			if(!me->query_temp("xy/renwu1_64") )
				me->set_temp("xy/renwu1_64",1);//֪ͨ���Ҽ��μ���Ϧ���
			say("ֻ�����Ҽ�ȴ�����Ǳ�ϵ��ƪ����Ŀ���������Ҳ��֪����û����������˵�Ļ���",me);
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);
}
NPC_END;




