//pub_xiaogueizi.h
//�ز� 2002-12-09

NPC_BEGIN(CNpub_xiaogueizi);

virtual void create()
{
	set_name("��С��", "xiao guei zi");
	//	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�");
	set("title", "������");
	set("gender", "����");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("per", 30);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);
	
	set("hp", 6500);
	set("max_hp", 6500);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 10);
	
	set("combat_exp", 400000);
	set("score", 40000);

    set_skill("literate", 1);
	set_skill("force", 10);
	set_skill("dodge", 200);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("whip", 10);
	set_skill("blade", 10);
	set_skill("sword", 10);
	set_skill("hand", 10);
	set_skill("claw", 10);
	set_skill("houquan", 10);
	set_skill("yunlong_xinfa", 10);
	set_skill("yunlong_shengong", 10);
	set_skill("wuhu_duanmendao", 10);
	set_skill("yunlong_jian", 10);
	set_skill("yunlong_shenfa", 10);
	set_skill("yunlong_bian", 10);
	set_skill("yunlong_shou", 10);
	set_skill("yunlong_zhua", 10);
	
	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu_duanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");
	
	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");

	create_family("������",2,"����");
	
	set("chat_chance", 3);
	
	add_money(1000);
	set("no_talk",1);
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "С������:���������ţ������ޱߣ�����˼���������ñȶ�������......��";
	case 1:
		random_move();
		return 0;
	case 2:
		return "С������:�������Ҳ��������ٷ磬�������Σ��������й������ؽ��ǿ���ı��䣡��";
	}
	
	return 0;
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("wei/renwu1"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("��С�����������߸�����", "dating",me);	
			AddMenuItem("��С��������æ������", "help",me);
			if(me->query_temp("wei/renwu9_1"))
			{
				AddMenuItem("��С������˪������", "shuanger",me);
			}
			if(me->query("wei/count")==7)
			{
				AddMenuItem("��С����ȡ�����ŵĽ���", "jiangli",me);
			}
			SendMenu(me);
		}
		else if(!strcmp(ask, "dating") )
		{
			say( "�������������ң�����Ժ����ô����Ϊʲô��Ҫ�������߸���",me);   
			say( "������֪���������߸�������Ȼ�Ը���죬���������Ǿ�����˫����Ů����Ů������Ժ�����Щ��������ܼ����ǵ����֮һѽ��",me);   
			say( "С������ָͷһ����������˪��������ˣ�����������������Ȼ��Щ����Ƣ�����������������������ˣ��嵶Ƽ��ɰ����������������������Ʊ�����ѩ����������͸��ȴ���Բ�ס��Ҫ�������˽⡣",me);   
			me->set_temp("wei/renwu1_2",1);
			SendMenu(me);
		}
		else if(!strcmp(ask, "shuanger") )
		{
			say( "С��˵����˪��ѽ����ֻ֪�����ң�",me);   
			if(!me->query_temp("wei/renwu9_2"))
			{
				say( "С���ó�һ��ֽ�������ֱ������滭�˼��ʣ�Ȼ��ݸ����㡣",me);   
				me->set_temp("wei/renwu9_2",1);//�õ�С��ī��
				CContainer * hua=load_item("redrose");
				hua->set_name( "С��ī��","xiaobao hua");
				hua->set("long","����һ��ë�ʻ������ﻭ����Ȼ��������׾�ӣ����Կ��Կ�����һ�������ӵ����ˣ�����һ�Ŵ��ϣ��ƺ��ǵ���ʲô����ģ����");
				hua->move(me);
			}
			SendMenu(me);
		}
		else if(!strcmp(ask, "help") )
		{
			if(!me->query("wei/count"))
			{
				if(!me->query_temp("wei/renwu1_2"))
				{
					tell_object(me, "$YELС�����ȵء�������һ����\n");   
					tell_object(me, "С����ֵ������ʵ���������ʶ����Щ�����𣿡�");   
				}
				else
				{
					tell_object(me, "$YELС�����˵�����������\n");   
					tell_object(me, "С�����˵�˵��:��̫���ˣ���Ҫ�ǰ����һ������ţ���һ���ú�лл�㣡��");   
					me->set("wei/renwu1",1);
				}
			}
			else
			{
				char msg[255];
				tell_object(me, "$YELС����������ļ��һ����С�ӣ��úøɵ����ӣ�\n");   
				tell_object(me, snprintf(msg, 255,"���Ѿ������ҵ���%d�����ţ�������ܰ����ҵ��������ţ���һ�����س�л�㡣",me->query("wei/count")));   
				me->set("wei/renwu1",1);
			}
		}
		else if(!strcmp(ask, "jiangli") )
		{
			//��ȡ���ս���
			say( "�ҳ���ûд�꣬����ô������ĵ��أ�",me); 
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me, ask);
}

virtual void die()
{
	CContainer * env = load_room("��������Ժ");
	if(env->query("С��"))
	{
		env->del("С��");
	}
	CNpc::die();
}
NPC_END;
