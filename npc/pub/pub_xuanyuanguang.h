//pub_xuanyuanguang ��ԯ��
//�ز� 2002��3��21

NPC_BEGIN(CNpub_xuanyuanguang);

virtual void create()
{
	set_name("��ԯ��","xuanyuan��guang");
	set("title", "��Ĺ� ");
	set("foolid",151);        
	set("gender", "����");
	set("age", 46);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",young_woman8);
	
	set("mp", 1400);
	set("max_mp", 1400);
	set("mp_factor", 30);
	set("max_mp", 1000);
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("chat_chance", 5);
	set_skill("unarmed", 90);
	set_skill("sword", 90);
	set_skill("force", 90);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("hengshan_jian", 90);
	set_skill("lingxu_bu", 90);
	
	map_skill("sword", "hengshan_jian");
	map_skill("parry", "hengshan_jian");
	map_skill("dodge", "lingxu_bu");
	
	carry_object("changjian")->wield();
	carry_object("cheng_cloth")->wear();
	//set("task",1);
	set("no_talk",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task"))
	{
		int num,num1;
		int key;
		char msg[255];
		static char bocai[125][20]=
		{
			"yuchi","yuchi","yeerba","yadan","xiaren2","suanmei","soup2","soup","shrimp","sherou","shanhu_baicai","rice","nang",
				"mian","marz","liuli_qiezi","kaoyangtui","kaoya","jiaxin_biji","gourou","egg","chicken","caomei","bocai_fentiao",
				"birddie","basi_shanyao","baozi","zongzi","backleg","yezi","yangxin","yangrou","yangjing","xueli","xiang",
				"turou","tofu","tanghulu","suya","suji","rice3","qingshui_hulu","qingke_m","qingcha","puercha","pork","peanut",
				"paomo","mizhitianou","mitao","mala_doufu","jiudai","jitui","gouroutang","furong_huagu","fotiaoqiang","fish",
				"baozi2","zhutou","yaofen","tianqi","shanshen","mixian","mangguo","huotui2","huotui","hulu2","hu","hdjiudai",
				"hamigua","gao","fuling","duanchang","bicanfeng","yuchandan","yaopin_1","xxqingxin_san","xuelian","shedangao",
				"putizi","menghan_yao","luobo","kongquedan","jingxin_san","hedinghong","geng","gaoyao","gao4","gao3","xuelian2",
				"yaopin_2","xiaohuan_dan","tianxiang_gao","shouwu","shedan","nverhong","jiu","fengmi","fen","yaopin_3",
				"sanxiaosan","jiuping2","jiuping","jiuhua","jinchuang_yao","jinchuang","honey_san","heiyugao","guiyuan","feicui",
				"baiyunwan","zhujingchan","zhuguo","zaisheng","wuchangdan","dahuan_dan","renshen","guiling","baixiang",
				"renshenguo","x_drug","labazhou","baixiang","wuchangdan","renshen",
		};
		if(me->query("age")<16)
			return notify_fail("�Ĳ�����ѧ�ʣ���Ҫ���㳤������������");
		if(!strlen(ask))
		{
			AddMenuItem("��21��", "y", me);
		}
		else if(!strcmp(ask,"y"))
		{
			say("���ʹ���\nһ��Ը�ķ��䣻\n����ÿע1000��\n������Ϸ�еĵ�������Ϊʤ��\n�ġ�������ͬʱׯ��ʤ��\n�塢��һ�����ʿ��Ի�ö��⽱����������֤���Կ϶���á�",me);
			AddMenuItem("��֪���ˣ���ʼ�ɣ�","start",me);
			AddMenuItem("�������Ҳ�ϲ��","over",me);
		}
		else if(!strcmp(ask,"start"))
		{
			num=me_play(me);
			if(!num)
			{
				num1=npc_play(me);
				if(!num1)
				{
					AddMenuItem("���Լ��ĵ���","view",me);
					AddMenuItem("��һ����","add",me);
					AddMenuItem("����","end1",me);
				}
			}
		}
		else if(!strcmp(ask,"add"))
		{
			num=me_play(me);
			if(!num)
			{
				if(me->query_temp("21/npc_count")<15)
					num1=npc_play(me);
				else if(me->query_temp("21/npc_count")<17 && me->query_temp("21/npc_count")<me->query_temp("21/me_count"))
				{
					tell_object(me,"��ԯ�⿴�����Լ��ĵ��ƣ���ԥ��һ�£�һ���Ĵӿڴ����ͳ�1000���ŵ��˶����ϣ���Ҫ��һ���ơ�");
					me->add_temp("21/npc_idx",1);
					if(random(3))
					{
						key=20-me->query_temp("21/npc_count");
						if(key>10)key=10;
						me->add_temp("21/npc_count",key);
					}
					else
					{
						key=random(20-me->query_temp("21/npc_count"))+1;
						if(key>10)key=10;
						me->add_temp("21/npc_count",key);
					}
					num1=0;
					tell_object(me,snprintf(msg, 255, "��ԯ����ס��������������������ƣ���ϸһ������ʱ����������һ�����������̵Ľ��Ʒ��˳�����\n�����ȥһ��,���������Ǹ�$HIR%d$COM��", key));
					tell_object(me,snprintf(msg, 255, "�����һ����ԯ���Ǳߣ��������������ϴ�Լ�Ѿ�Ѻ����$HIR%d$COM���ҡ�\n",me->query_temp("21/npc_idx")*1000));
				}
				else
				{
					tell_object(me,"��ԯ�⿴�����Լ��ĵ��ƣ������룬ҡ��ҡͷ�����ٽ���Ҫ���ˡ�");
					num1=0;
				}
				if(!num1)
				{
					AddMenuItem("���Լ��ĵ���","view",me);
					AddMenuItem("��һ����","add",me);
					AddMenuItem("����","end1",me);
				}
			}
		}
		else if(!strcmp(ask,"view"))
		{
			if(me->query_temp("21/me_JQK"))
				tell_object(me,snprintf(msg,255,"�����ڵĵ�����$HIR %d ���$COM��\n",me->query_temp("21/me_count")));
			else
				tell_object(me, snprintf(msg,255,"�����ڵĵ�����$HIR %d $COM�㡣\n",me->query_temp("21/me_count")));
			AddMenuItem("���Լ��ĵ���","view",me);
			AddMenuItem("��һ����","add",me);
			AddMenuItem("����","end1",me);
		}
		else if(!strcmp(ask,"end1"))
		{
			if(me->query_temp("21/me_count")>me->query_temp("21/npc_count") &&me->query_temp("21/npc_count")<17 )
			{
				tell_object(me,"$HIR����뿪�ƣ���ԯ�⿴�����Լ��ĵ��ƣ����һ������С�ӱ𶯣��һ�Ҫ�ƣ����ŵ��㲻����֨���ˡ�");
				me->add_temp("21/npc_idx",1);
				if(random(3))
				{
					key=20-me->query_temp("21/npc_count");
					if(key>10)key=10;
					key=random(key)+1;
					me->add_temp("21/npc_count",key);
				}
				else
				{
					key=random(20-me->query_temp("21/npc_count"))+1;
					if(key>10)key=10;
					key=random(key)+1;
					me->add_temp("21/npc_count",key);
				}
				tell_object(me,snprintf(msg, 255, "��ԯ������1000���ҵ������ϣ�����������һ���ƣ�����������ֱ�ӷ��˳�����\n�����ȥһ��,���������Ǹ�$HIR%d$COM��", key));
				tell_object(me,snprintf(msg, 255, "�����һ����ԯ���Ǳߣ��������������ϴ�Լ�Ѿ�Ѻ����$HIR%d$COM���ҡ�\n",me->query_temp("21/npc_idx")*1000));
				AddMenuItem("���Լ��ĵ���","view",me);
				AddMenuItem("��һ����","add",me);
				AddMenuItem("����","end1",me);
			}
			else
			{
				if(me->query_temp("21/me_JQK"))
					tell_object(me,snprintf(msg,255,"�����ڵĵ����� %d ���",me->query_temp("21/me_count")));
				else
					tell_object(me, snprintf(msg,255,"�����ڵĵ����� %d ��",me->query_temp("21/me_count")));
				if(me->query_temp("21/npc_JQK"))
					tell_object(me, snprintf(msg,255,"��ԯ�����ڵĵ����� %d ���",me->query_temp("21/npc_count")));
				else
					tell_object(me, snprintf(msg,255,"��ԯ�����ڵĵ����� %d ��",me->query_temp("21/npc_count")));
				if(me->query_temp("21/me_count")>me->query_temp("21/npc_count"))
				{
					tell_object(me,"$HIC��ԯ���ݺݵ�˵��С�ӣ��������֣���ЩǮ����ȥ�ɣ�");	
					CMoney::Pay_Player(me, (me->query_temp("21/me_idx")+me->query_temp("21/npc_idx"))*1000);
					tell_object(me, snprintf(msg,255,"$HIR��Ц�����Ľ�������һ�ѽ�һ����˹������ִ�һ������Լ׬��%d���һ��С�ơ�",me->query_temp("21/npc_idx")*1000));
					if(me->query_temp("21/me_count")==21)
					{
						me->add_temp("21/me_21",1);
						if(me->query_temp("21/m_21")>=120)me->set_temp("21/m_21",120);
						CContainer * ob = load_item(bocai[random(me->query_temp("21/me_21"))]);
						tell_object(me, snprintf(msg,255,"$HIR�����㷭��������21�㣬��ԯ���ɥ�����������²��ò�������һ��%s�ݸ����㡣",ob->name(1)));
						ob->move(me);
					}
				}
				else if(me->query_temp("21/me_count")==me->query_temp("21/npc_count"))
				{
					if(me->query_temp("21/me_JQK")>me->query_temp("21/npc_JQK"))
					{
						tell_object(me,"$HIC��ԯ���������۾��������ŵĿ�����˵��С�ӣ������ֻ���Ҵ��㣿");	
						CMoney::Pay_Player(me, (me->query_temp("21/me_idx")+me->query_temp("21/npc_idx"))*1000);
						tell_object(me, snprintf(msg,255,"$HIR��ϲ���̵�һ�����Ŵ���ԯ����������ƣ���һֻ��˳�ֽ�������һ�ѽ�һ����˹������ִ�һ������Լ׬��%d���һ��С�ơ�",me->query_temp("21/npc_idx")*1000));
					}
					else if(me->query_temp("21/me_JQK")==me->query_temp("21/npc_JQK"))
					{
						tell_object(me,"$HIC��ԯ�����Ц��˵��С�ӣ�����ĺ�ù�������Сһ��������ׯ���������㣡");
						tell_object(me, "���ɥ����������$HIC��ԯ��$COM�ֺǺǵĽ���ǰ��һ�ѽ�һ��������Ŀڴ���");
						tell_object(me, snprintf(msg,255,"$HIR�㲻���ĵķ��˷��Լ���Ǯ����������һ�δ�Լ����%d�顣",me->query_temp("21/me_idx")*1000));
					}
					else
					{
						tell_object(me, "$HIC���ɥ������������ԯ���ֺǺǵĽ���ǰ��һ�ѽ�һ��������Ŀڴ���");
						tell_object(me, snprintf(msg,255,"$HIC�㲻���ĵķ��˷��Լ���Ǯ����������һ�δ�Լ����%d�顣",me->query_temp("21/me_idx")*1000));
					}
				}
				else
				{
					tell_object(me, "$HIC���ɥ������������ԯ���ֺǺǵĽ���ǰ��һ�ѽ�һ��������Ŀڴ���");
					tell_object(me, snprintf(msg,255,"$HIC�㲻���ĵķ��˷��Լ���Ǯ����������һ�δ�Լ����%d�顣",me->query_temp("21/me_idx")*1000));
				}
				me->delete_temp("21/me_count");//�ܵ���
				me->delete_temp("21/me_idx");
				me->delete_temp("21/npc_count");//������
				me->delete_temp("21/npc_idx");
				me->delete_temp("21/me_JQK");//���
				me->delete_temp("21/npc_JQK");
				me->delete_temp("21/me_pai");//��
				me->delete_temp("21/npc_pai");
				me->add("repute",-10);
				return 1;
			}
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("����ô����Ķ����أ�",me);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

int me_play(CChar * me)
{
	char msg[255];
	if(!CMoney::Player_Pay(me, 1000))
	{
		say("���϶�û��Ǯ����ʲô��������ѽ��һ������ȥ��",me);
		return 1;
	}
	int nCount=random(11)+1;
	if(nCount > 10 )
	{
		if(!me->query_temp("21/me_JQK"))
			me->set_temp("21/me_JQK",1);
		else
		{
			me->delete_temp("21/me_JQK");
			me->add_temp("21/me_count",1);
		}
		switch(random(3))
		{
		case 1:
			me->set_temp("21/me_pai","��");
			break;
		case 2:
			me->set_temp("21/me_pai","��");
			break;
		case 3:
			me->set_temp("21/me_pai","��");
			break;
		}
	}
	else
	{
		me->add_temp("21/me_count",nCount);
		snprintf(msg, 255, "%d", nCount);
		me->set_temp("21/me_pai",msg);
	}
	me->add_temp("21/me_idx",1);
	tell_object(me,"$HIR���ˬ��Ĵӿڴ����ͳ�1000�飬�ӵ��˶����ϣ�˳��������һ���ơ�$COM");
	tell_object(me, snprintf(msg, 255, "��������������������������һ��$HIR %s $COM��", me->querystr_temp("21/me_pai")));
	tell_object(me,snprintf(msg, 255, "���Ѿ��ܹ�Ѻ����$HIR%d$COM���ҡ�\n",me->query_temp("21/me_idx")*1000));
	if(me->query_temp("21/me_count")>21)
	{
		if(me->query_temp("21/me_JQK"))
			tell_object(me,snprintf(msg,255,"�ܲ���,�����ڵĵ�����$HIR %d ���$COM,������21���Ѿ����ˣ��´����������ɣ�",me->query_temp("21/me_count")));
		else
			tell_object(me, snprintf(msg,255,"�ܲ���,�����ڵĵ�����$HIR %d $COM��,������21���Ѿ����ˣ��´����������ɣ�",me->query_temp("21/me_count")));
		tell_object(me,"$HIC���ɥ������������ԯ���ֺǺǵĽ���ǰ��һ�ѽ�һ��������Ŀڴ���");
		tell_object(me, snprintf(msg,255,"$HIC�㲻���ĵķ��˷��Լ���Ǯ����������һ�δ�Լ����%d�顣",me->query_temp("21/me_idx")*1000));
		me->delete_temp("21/me_count");//�ܵ���
		me->delete_temp("21/me_idx");
		me->delete_temp("21/npc_count");//������
		me->delete_temp("21/npc_idx");
		me->delete_temp("21/me_JQK");//���
		me->delete_temp("21/npc_JQK");
		me->delete_temp("21/me_pai");//��
		me->delete_temp("21/npc_pai");
		me->add("repute",-10);
		SendMenu(me);
		return 1;
	}
	SendMenu(me);
	return 0;
}

int npc_play(CChar * me)
{
	char msg[255];
	int nCount=random(11)+1;
	if(nCount > 10 )
	{
		if(!me->query_temp("21/npc_JQK"))
			me->set_temp("21/npcme_JQK",1);
		else
		{
			me->delete_temp("21/npc_JQK");
			me->add_temp("21/npc_count",1);
		}
		switch(random(3))
		{
		case 1:
			me->set_temp("21/npc_pai","��");
			break;
		case 2:
			me->set_temp("21/npc_pai","��");
			break;
		case 3:
			me->set_temp("21/npc_pai","��");
			break;
		}
	}
	else
	{
		me->add_temp("21/npc_count",nCount);
		snprintf(msg, 255, "%d", nCount);
		me->set_temp("21/npc_pai",msg);
	}
	me->add_temp("21/npc_idx",1);
	tell_object(me,"$HIR��ԯ���ˬ��Ĵӿڴ����ͳ�1000�飬�ӵ��˶����ϣ�˳��������һ���ơ�$COM");
	if(me->query_temp("21/npc_count")==nCount ||(!me->query_temp("21/npc_count") && me->query_temp("21/npc_JQK")))
		tell_object(me, "��ԯ�������������˵��ƣ������ַ�������");
	else
		tell_object(me, snprintf(msg, 255, "��ԯ������ɵĽ���ˤ�˳����������ȥһ��,���������Ǹ�$HIR%s$COM��", me->querystr_temp("21/npc_pai")));
	tell_object(me,snprintf(msg, 255, "�����һ����ԯ���Ǳߣ��������������ϴ�Լ�Ѿ�Ѻ����$HIR%d$COM���ҡ�\n",me->query_temp("21/npc_idx")*1000));
	if(me->query_temp("21/npc_count")>21)
	{
		if(me->query_temp("21/npc_JQK"))
			tell_object(me, snprintf(msg,255,"�����һ����Ц����������ù������������ڵĵ�����$HIR%d���$COM,�Ѿ�����Ӵ��",me->query_temp("21/npc_count")));
		else
			tell_object(me, snprintf(msg,255,"�����һ����Ц����������ù������������ڵĵ�����$HIR%d$COM��,�Ѿ�����Ӵ��",me->query_temp("21/npc_count")));
		tell_object(me,snprintf(msg,255,"$HIR��Ц�����Ľ�������һ�ѽ�һ����˹������ִ�һ������Լ׬��%d���һ��С�ơ�",me->query_temp("21/npc_idx")*1000));
		CMoney::Pay_Player(me, (me->query_temp("21/me_idx")+me->query_temp("21/npc_idx"))*1000);
		me->delete_temp("21/me_count");//�ܵ���
		me->delete_temp("21/me_idx");
		me->delete_temp("21/npc_count");//������
		me->delete_temp("21/npc_idx");
		me->delete_temp("21/me_JQK");//���
		me->delete_temp("21/npc_JQK");
		me->delete_temp("21/me_pai");//��
		me->delete_temp("21/npc_pai");
		me->add("repute",-10);
		return 1;
	}
	return 0;
}

NPC_END;




