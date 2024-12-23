//xy_xiaoyaonv.h ��ңŮ�����꣩
//�ز� 2002��12��12

NPC_BEGIN(CNxy_xiaoyaonv);

virtual void create()
{    
    set_name("��ңŮ", "xiao yao nv");
    set("long","ֻ������Լʮһ�����꣬�����������ף���������̬�����̫������ϼ������ܽ�س��̲�����");	
    set("title","��ң��");
	set("gender", "Ů��"); 
    set("age", 12);

    set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 32);
    set("per", 40);

	set("help",1);//�������NPC�ⷽ

    set("icon",12);
	create_family("��ң��", 1, "����");

    set("max_hp", 16000);
    set("mp", 7000);
    set("max_mp", 7000);
    set("mp_factor", 60); 
    set("combat_exp", 4000000); 
	
	set("no_kill",1);

    set_skill("force", 200);
    set_skill("beiming_shengong", 200);
    set_skill("dodge", 200);
    set_skill("lingboweibu", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("xiaoyao_dao", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
	set_skill("xiaoyao_jian", 200);
	set_skill("sword", 200);
	set_skill("literate", 200);
	
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei_shou");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("parry", "xiaoyao_dao");
	map_skill("blade", "xiaoyao_dao");
	map_skill("sword", "xiaoyao_jian");

    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");

    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("changjian")->wield();

	set("chat_chance", 70);
}

virtual char * chat_msg()
{
	if(querystr_temp("���")[0] && !query_temp("fight/is_fighting") )
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr_temp("���"));
		if(me && me->query_temp("xy/renwu3_1"))
		{
			delete_temp("���");
			((CChar *)me)->disable_player("������");
			((CChar *)me)->call_out(do_tanhua, 1);
		}
	}
	return 0;
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan3"))
	{
	case 0:
		tell_object(me, "\n$HICֻ����ǰ��Ů����Լʮһ�����꣬�����������ף���������̬�����̫������ϼ������ܽ�س��̲�����");
		me->add_temp("xy/tanhuan3",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
		{
			if(EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))
				tell_object(me, "$HIC�㲻�ɴ󾪣��ⲻ����ңŮ��˭��æ��ǰ��ݣ���ͽ��������٣���ʦ��ˡ���");
			else
				tell_object(me, "$HIC�㲻�ɴ󾪣��ⲻ����ңŮ��˭��æ��ǰ��ݣ�������������٣�����ʦˡ���");
		}
		else
			tell_object(me, "$HIC�㲻�ɴ󾪣��ⲻ����ңŮ��˭��æ��ǰ���񣺡�������٣�����ǰ��ˡ���");
		me->add_temp("xy/tanhuan3",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
		{
			if(EQUALSTR(me->querystr("family/master_id"), "xiaoyao nv"))
				tell_object(me, "$HIC��ңŮһ����㵣����������ϴ����ˣ�����ô�������ܵ���ʦ������");
			else
				tell_object(me, "$HIC��ңŮһ����㵣����������ϴ����ˣ�����ô�������ܵ�����ʦ����");
		}
		else
			tell_object(me, "$HIC��ңŮһ����㵣����������ϴ����ˣ�����ô�������ܵ�ǰ������");
		me->add_temp("xy/tanhuan3",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "$HIC����̧ͷϸ����һʱ���Լ�Ҳ��Ϳ�ˣ���ǰ����������ңŮ��������ȴ���Լ���Ϥ����ңŮС�˺ܶ࣬����Ī������ѵ��Լ������β��ɣ�");
		me->delete_temp("xy/tanhuan3");
		me->set_temp("xy/renwu3_3",1);//�ȳ���ңŮ
		me->enable_player();
		break;
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("xy/renwu3_3") && !me->query_temp("xy/renwu3_5") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("����ңŮѯ�ʹ�������ѩ��������","xuelian",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "xuelian") )
		{
			say("��ңŮ˵����������ѩ����Ȼ�ٵ���ֻ����ЩС������Һ����꣬�ϲ����Ҳ��ţ����������˾ͺ��ˡ����ǻ��Ǹϻ���ң�����ֳ�Ϊ������ҩ���ưɡ�",me);
			me->set_temp("xy/renwu3_4",1);//�ҵ�����ѩ��������ңŮ����ң��Ժ��
			set_leader(me);
			SendMenu(me);
			tell_object(me,"\n$HIY��ңŮ������ʼ������һ���ж���\n");
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




