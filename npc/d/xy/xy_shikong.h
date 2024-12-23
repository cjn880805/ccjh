//xy_shima.h ˾������
//�ز� 2003��1��25

NPC_BEGIN(CNxy_shikong);

virtual void create()
{    
    set_name("˾������", "shikong zixu");
    set("long","����Ŀ�Ⱥͣ��������ƺ�ɫ����ֱ�����أ�һϮ���Ļ�ɫ�������Ʈ�����õ�֮���ˡ�");	
	set("gender", "����");
	set("age", 63);
	set("foolid",127);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);
	set("icon",taoist);	
	
	set("hp",30000);
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 70000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 400);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");

	create_family("�䵱��", 3, "����");
	set("class", "taoist");

	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_kill",1);

}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(EQUALSTR(environment()->querystr("base_name"),"��ң��׷�¹۾�˼ͥ" ))
	{
		if(me->query("xy/renwu5_3") && !me->query("xy/renwu6") )
		{
			say(snprintf(msg, 255, "˾�����������˵�ͷ����%s���ϼ���豣��粻���������������£����磿��",query_respect(me)), me);
			say("��æ��������ǰ���������м�������ֻ���������������̶�ʦ����δ����Ͷ���ɣ�����ǰ�����¡���", me);
			say("˾���������ִ�����ᣬΨ��̾�˿��������������ұ�����Ե���Բ���ǿ������һ�仰���˷������ĺ�����һ����ӽ�����������ʥ����������ͼ������ң�Ρ�����", me);
			say(snprintf(msg, 255, "˾�������ֶ���˵�������Ҽ����Ƕ�ʦ�������������أ���С����������ˣ�����Ե���ڴˣ�%s���ɣ���",query_respect(me)), me);
			me->set("xy/renwu6",1);//��ң��������������֣�������ߧ����
			SendMenu(me);
		}
		return 1;
	}
	else if(EQUALSTR(environment()->querystr("base_name"),"��ң��׷�¹ۻ���ͥ" ))
	{
		if(!me->query("xy/renwu5_3"))
		{
			if(me->query("xy/renwu5_2") )
			{
				say(snprintf(msg, 255, "˾�������������֪%s�Ƿ��Ѿ�׼��������ͽ���һ�������أ���",query_respect(me)), me);
				SendMenu(me);
			}
			else if(me->query("xy/renwu5_1") && me->query_temp("xy/renwu5_1") )
			{
				if(!me->query_temp("xy/renwu5_2"))
				{
					if(! strlen(ask))
					{
						say(snprintf(msg, 255, "˾�����������%s�ɷ��Ȼش�ƶ���������⣿��",query_respect(me)), me);
						AddMenuItem("Ը��", "yes", me);
						AddMenuItem("����", "", me);
					}
					else if(!strcmp(ask, "yes") )
					{
						say("˾��������˵�ͷ��", me);
						me->set_temp("xy/renwu5_2",1);//׼���ش�����
					}
				}
				else
				{
					switch(me->query_temp("xy/renwu5_3"))
					{
					case 0:
						say("˾�������ʵ����������ߣ���Ҳ����", me);
						break;
					case 1:
						say("˾�������ʵ����������ߣ���Ҳ����", me);
						break;
					case 2:
						say("˾�������ʵ���������ߣ���Ҳ����", me);
						break;
					case 3:
						say("˾�������ʵ����������ߣ���Ҳ����", me);
						break;
					case 4:
						say("˾�������ʵ�����÷���μ�����", me);
						break;
					case 5:
						say("˾�������ʵ����������ʱ����", me);
						break;
					case 6:
						say("˾�������ʵ�������ï�μ�����", me);
						break;
					case 7:
						say("˾�������ʵ������շ���ʱ����", me);
						break;
					}
					AddMenuItem("�ش�", "$2flatter $1 $2", me);
				}
			}
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}  

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if(me->query("xy/renwu5") && !me->query("xy/renwu6") )
	{
		if (!strcmp(comm,"flatter") && me->query_temp("xy/renwu5_2") )
			return do_flatter(me,arg);
	}

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("��ʲô�� ");

	tell_object(me,snprintf(msg,255,"������˵������%s��", arg));
	me->add_temp("xy/renwu5_3",1);//�ش��������Ŀ
	
	switch(me->query_temp("xy/renwu5_3"))
	{
	case 1:
		if(strstr(arg, "��") && strstr(arg, "��") && strstr(arg, "��"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 2:
		if(strstr(arg, "������") && strstr(arg, "������") && strstr(arg, "���׻�") && strstr(arg, "����ȸ"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 3:
		if(strstr(arg, "��") && strstr(arg, "��") && strstr(arg, "��") 
			&& strstr(arg, "��")&& strstr(arg, "��"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 4:
		if(strstr(arg, "ʫ") && strstr(arg, "��") && strstr(arg, "��") 
			&& strstr(arg, "��")&& strstr(arg, "��")&& strstr(arg, "����"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 5:
		if(strstr(arg, "��"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 6:
		if(strstr(arg, "��"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 7:
		if(strstr(arg, "��"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		break;
	case 8:
		if(strstr(arg, "��"))
			me->add_temp("xy/renwu5_4",1);//�ش���ȷ�������Ŀ
		if(me->query_temp("xy/renwu5_3")==8 && me->query_temp("xy/renwu5_4")==8)
		{
			tell_object(me,snprintf(msg, 255, "\n$HIR˾�������ͷ��������ң�͵ܹ�Ȼû�����ˣ���λ%s���ʴ�ӱ����ѧ���ţ��ҽ����ѣ���ѧ��֮�ġ���",query_respect(me)));
			tell_object(me,"$HIR˾�������ͷ��������������Ķ�Լ��ͽ���������ʤ���ˡ�\n");
			me->set("xy/renwu5_2",1);//ͨ��˾������Ŀ���
		}
		break;
	}
	return 1;
}


NPC_END;