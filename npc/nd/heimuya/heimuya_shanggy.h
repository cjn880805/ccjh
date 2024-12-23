//heimuya_shanggy.h �Ϲ���
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_shanggy);

virtual void create()
{
	set_name("�Ϲٷ�", "shangguan yun");
	set("gender", "����" );
	set("age", 40);
	set("title" , "������̰׻��ó���");
	set("long", "�����ֳ���, ˫Ŀ�����Ȼ, �������ơ�");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);
 	set("icon",young_man5);

	set("hp",800);
	set("max_hp", 800);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 200);
	set("combat_exp", 360000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu_bufa", 120);
	set_skill("lingshe_zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("�������",2,"���� �׻��ó���");

	set("chat_chance", 3);
	
	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
//	carry_object("zhenzhu")->wear();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	say("���ǻ���֮��, ��ô����ͽ�ء�׳ʿ������ذ�!", me);
	SendMenu(me);
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if(me->query_temp("ry/renwu3_1") && !me->query_temp("ry/renwu3_2"))
	{
		if (obj->query("ry/heimu_ling") &&  EQUALSTR(obj->querystr("owner1"), me->id(1)))
		{
			say( "�Ϲٷ�����ã�������������һ�¿���������Ҿ�������ȥ����", me);
			me->set_temp("ry/renwu3_2",1);//�Ϲٷ���ܺ�ľ�׼���Կ���
			destruct(obj);
			SendMenu(me);
			return 1;
		}
	}
	else  
    {
		message_vision("�Ϲٷ��$N˵�����ˣ�ң���\n", me);
        this->kill_ob(me);
    }
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu3_2") && !me->query_temp("ry/renwu3_3"))
	{
		if(! strlen(ask))
		{
			say("�Ϲٷ��ʵ������ĳ���¡�����Ӣ��������ѵ���������Ե���ݣ���",me);
			AddMenuItem("ն�ݳ�������Ů���ף�����һ��","one",me);
			AddMenuItem("ն�ݳ�������Ů���ף�ȫ������","two",me);
			AddMenuItem("ն��ɱ������Ů���ף�����һ��","three",me);
			AddMenuItem("ն�ݳ�������Ů���棬����һ��","four",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "one") )
		{
			tell_object(me,"\n$HIR�Ϲٷ�����ţ�����û���⣬�������ȥ�ˣ���");
			tell_object(me,"\n$HIC�Ϲٷ�һ���֣�ֻ�����֮�л�������һֻ����������װ��ʮ��ʯ�ס�");
			tell_object(me,"$HIC�Ϲٷ�ȵ���������λӢ����ȥ����");
			tell_object(me,"$HIC����һ�������˵�����");
			tell_object(me, "\n$HICͭ�����죬�����������ߡ�ԭ�����н������̣�����¨������ȥ��");
			tell_object(me, "$HIC������ס��������̧ͷ������ֻ��ͷ����������ǣ����ľ����ʵ�ߵ��������㲻�ɵ�������֣���ס�����ӡ�");
			tell_object(me, "$HIC��ҹ֮�У��Կɼ���һƬƬ���ƴ�ͷ��Ʈ�����ٹ�һ�ᣬ���������������ף������ڳ�����һƬ�����ƻ�Ҳ�������ˡ�");
			
			me->set_temp("ry/renwu3_3",1);//����ںţ���ʼ����
			call_out(goto_heimuya, 10,me->object_id());
		}
		else if(!strcmp(ask, "two") ||!strcmp(ask, "three") ||!strcmp(ask, "four") )
		{
			message_vision("�Ϲٷ��$N˵���󵨿�ͽ����Ȼ������������ɻ죬������\n", me);
			this->kill_ob(me);
			me->delete_temp("ry");
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

static void goto_heimuya(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = ob->environment();
	CChar * me =  (CChar *)env->Present(param1);
	if(me)
	{
		tell_object(me, "\n$HIC�������ã�������ͣ���Ϲ�����������̤��������\n");
		me->move (load_room("��ľ�¶�ͨ��1��"));
		tell_object(me, "\n$HIRû�뵽��һ̤�������Ϲ��ƾͺȵ�:����λ����ץס��С�ӣ��������������ϵĺ�ľ���������������\n");
		me->set_temp("ry/renwu4_1",1);//��ʼ�´���ľ�¶�
	}
}

NPC_END;