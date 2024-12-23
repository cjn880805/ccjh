//xy_tielao1.h	��ɽͯ�ѣ��չ��ң�
//�ز� 2002��12��2

NPC_BEGIN(CNxy_tielao1);

void create()
{
	set_name("��ɽ����",  "tong lao");
	set("long", "������ȥ����һλ�˾����С�������ɫ֮��ĳ����ȴ�������䲻̫�����");
	set("gender", "Ů��");
	set("per", 20);
	set("age", 26);
	set("icon",4);

	set("title","��ң��");
	create_family("��ң��", 1, "����");
	
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("hp", 5000);
	set("max_hp", 5000);
	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 50);

	set("combat_exp", 950000);
	set("chat_chance", 30);

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
    set_skill("sword",100);
	set_skill("literate", 100);

	set_skill("zhemei_shou",100);
	set_skill("liuyang_zhang",100);
	set_skill("yueying_wubu",100);
	set_skill("bahuang_gong", 100);
	set_skill("xiaoyao_jian", 100);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "xiaoyao_jian");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	
 	carry_object("qingyi")->wear();

	set("no_kill",1);
	set("help",1);
	set("no_huan",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * env=me->environment();
	if((EQUALSTR(env->querystr("base_name"), "��ң�ȱչ���" )))
	{
		if(me->query("xy/renwu7_1") && !me->query("xy/renwu7_2") && !is_fighting()) 
		{	
			CContainer * shiti=env->present("corpse");
			if(!shiti)
			{
				shiti=load_npc("temp");
				CContainer * corpse =CCorpse::MakeCorpse((CChar *)shiti, NULL);
				corpse->set("name","���ʵ�ʬ��");
				corpse->set("long","����һ�����ʵ�ʬ�塣");
				corpse->move(env);
			}
			me->disable_player("������");
			me->call_out(do_tanhua, 1);
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me,"\n$HIC��ɽ���Ѷ���˵����������Ǳչ����ˣ��˵ؼ������ܣ�Ѱ���˵����޷�����ġ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me,"$HIC��ÿ����ʱ���붨���̣���ʱ��ɷ��ģ����¼���΢�����죬Ҳ���ܵ������߻���ħ��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me,"$HIC�������������������������ʱ�䣬���п��Ա����������뿪��ʯ�ҡ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me,"$HIC���⡮�˻�����Ψ�Ҷ��𹬡��ھ��أ�����ʳ��Ѫά��������ʦֶ����ÿ����Щ���ʵ�ʬ���������ʹ�á���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me,"\n$HIC��˵������ʦ�����ģ���һ��ȫ�������Ҵ�������ˣ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me,"\n$HIC��ɽ��������üͷ�������Բ����ĵؿ�����һ�ۣ���ҡ��ҡͷ����̾��һ������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me,"\n$HIC��ɽ��������һ�Ե�ʬ�壬����ҧ���侱���Ͽ�����Ѫ�����ڹ��������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me,"$HIC�漴��ϥ���£�����ʳָָ�죬����ʳָָ�أ����кٵ�һ�����ǿ����������������������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me,"$HIC������ɽ���ѱ����³����İ�����ס���Դ���Χ�����Ʋ�ɢ������������Ũ����Ϊһ�Ű���������Ŀ����û�ˡ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me,"$HIC����ֻ������ȫ��ǽڸ�����죬���籬����");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me,"\n$HIC�������ã����������ὥϡ���������Ű���Ҳ�������ˣ�ֻ����ɽ���ѱǿ��в����������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 11:
		tell_object(me,"$HIC���ð�����������ɽ��������˫�ۣ�����վ��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 12:
		tell_object(me,"\n$HIC��ֻ������ɽ�����������������������������кβ�ͬ��ȴҲ˵��������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 13:
		tell_object(me,"\n$HIC��ɽ����˵���������ˣ����ȥ����ѰЩʬ������ɣ���\n");
		me->add_temp("xy/tanhuan",1);
		me->delete_temp("xy/tanhuan");
		me->set("xy/renwu7_2",1);//��ʽ��ʼ����ɽ���ѻ���
		me->enable_player();
		CContainer * shiti=env->present("corpse");
		if(shiti)
			destruct(shiti);
		double value = 600;		//10����
		time_t t;
		time(&t);
		t += (time_t)value;	
		me->set("xy/renwu7_time",t);//�����´ν���ʬ���ʱ�䣬���Ϊ10����
		break;
	}
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->query("xy/renwu7_2"))
	{
		if(EQUALSTR(ob->querystr("base_name"), "corpse_ob") )
		{
			time_t t;
			time(&t);
			CContainer * XyNpc;
			CChar * XyNpc1;
			CContainer * env;
			if(t>me->query("xy/renwu7_time") )
			{
				if(!me->query("xy/renwu7_pause") )
				{
					double value = 600;		//10����
					t += (time_t)value;	
					me->set("xy/renwu7_time",t);//�����´ν���ʬ���ʱ�䣬���Ϊ10����
					me->add("xy/renwu7_count",1);//����ɽ����һ�����ʵ�ʬ��
					if(me->query("xy/renwu7_count")>=40)
					{
						//�����������
						me->disable_player("������");
						me->call_out(do_tanhua1,1);
						set("per",40);
						set("icon",young_woman5);
						return 1;
					}
					else if(!(me->query("xy/renwu7_count")%12))
					{
						me->set("xy/renwu7_pause",1);//�����¼������ڼ佫���ٽ���ʬ��
						me->add("xy/renwu7_3",1);//������ɽ���ѵ�����
						
						switch(me->query("xy/renwu7_3"))
						{
						case 1:
							env=load_room("��ң�ȴ���Ǿ���1");
							XyNpc=env->present("meng mian nv");
							if(!XyNpc)
							{
								XyNpc1=load_npc("xy_liqiouheng2");
								XyNpc1->set("owner",me->id(1));
								XyNpc1->move(env);
								XyNpc1->call_out(do_daoluan1,10);
							}
							break;
						case 2:
							env=load_room("��ң�ȴ���Ǿ���1");
							XyNpc=env->present("li qiou heng");
							if(!XyNpc)
							{
								XyNpc1=load_npc("xy_liqiouheng1");
								XyNpc1->set("owner1",me->id(1));
								XyNpc1->move(env);
								XyNpc1->call_out(do_daoluan2,10);
								me->set_temp("xy/renwu7_4",1);//����۵ڶ��ο�ʼ������
							}
							break;
						case 3:
							env=load_room("��ң�ȴ���Ǿ���1");
							XyNpc=env->present("li qiou heng");
							if(!XyNpc)
							{
								XyNpc1=load_npc("xy_liqiouheng3");
								XyNpc1->set("owner",me->id(1));
								XyNpc1->move(env);
								XyNpc1->call_out(do_daoluan3,10);
							}
							break;
						}
					}
					else if(me->query("xy/renwu7_pause") )
						me->del("xy/renwu7_pause");
					char msg[255];
					tell_object(me, snprintf(msg, 255,"\n$HIC��ɽ����һ�ſڱ�ҧ��%s�ʺ��ϣ����ڹ�������������˱����Ѫ��",ob->name(1)));		
					tell_object(me,"$HIC�漴��ϥ���£�����ʳָָ�죬����ʳָָ�أ����кٵ�һ�����ǿ����������������������");
					tell_object(me,"$HIC������ɽ���ѱ����³����İ�����ס���Դ���Χ�����Ʋ�ɢ������������Ũ����Ϊһ�Ű���������Ŀ����û�ˡ�");
					tell_object(me,"$HIC����ֻ������ȫ��ǽڸ�����죬���籬����");
					tell_object(me,"\n$HIC�������ã����������ὥϡ���������Ű���Ҳ�������ˣ�ֻ����ɽ���ѱǿ��в����������");
					tell_object(me,"$HIC���ð�����������ɽ��������˫�ۣ�����վ��¶���˿�����΢Ц������лʦֶ��");
					tell_object(me,"\n$HIC��ֻ������ɽ�����������������������������кβ�ͬ��ȴҲ˵��������\n");
					destruct(ob);
					return 1;
				}
				else
				{
					tell_object(me,"\n$HIC��ɽ��������ʳָָ�죬����ʳָָ�أ�����ɮ�붨����ϥ��Ŀ�ڵء�\n");
					switch(me->query("xy/renwu7_3"))
					{
					case 1:
						env=load_room("��ң�ȴ���Ǿ���1");
						XyNpc=env->present("meng mian nv");
						if(!XyNpc)
						{
							XyNpc1=load_npc("xy_liqiouheng2");
							XyNpc1->set("owner",me->id(1));
							XyNpc1->move(env);
							XyNpc1->call_out(do_daoluan1,10);
						}
						break;
					case 2:
						env=load_room("��ң�ȴ���Ǿ���1");
						XyNpc=env->present("li qiou heng");
						if(!XyNpc)
						{
							XyNpc1=load_npc("xy_liqiouheng1");
							XyNpc1->set("owner1",me->id(1));
							XyNpc1->move(env);
							XyNpc1->call_out(do_daoluan2,10);
							me->set_temp("xy/renwu7_4",1);//����۵ڶ��ο�ʼ������
						}
						break;
					case 3:
						env=load_room("��ң�ȴ���Ǿ���1");
						XyNpc=env->present("li qiou heng");
						if(!XyNpc)
						{
							XyNpc1=load_npc("xy_liqiouheng3");
							XyNpc1->set("owner",me->id(1));
							XyNpc1->move(env);
							XyNpc1->call_out(do_daoluan3,10);
						}
						break;
					case 4:
						me->del("xy/renwu7_pause");
						break;
					}
				}
			}
			else
			{
				tell_object(me,"\n$HIC��ɽ��������ʳָָ�죬����ʳָָ�أ�����ɮ�붨����ϥ��Ŀ�ڵء�");
				tell_object(me,"$HIC��ɽ��������˵�������������������⡮�˻�����Ψ�Ҷ��𹬡��ھ��أ����������ʦֶС�İ��һ�������");
			}
		}
	}
	return 0;
}

static void do_daoluan1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * liqiouheng = (CChar *)ob;
	if(liqiouheng->querystr("owner")[0])
	{
		CUser * me=find_online(liqiouheng->querystr("owner"));
		if(me)
		{
			switch(liqiouheng->query_temp("xy/daoluan1"))
			{
			case 0:
				tell_object(me, "\n$HICԶ������һ�������������");
				tell_object(me, "$HIC��������ö��������ڽ���ͯ��ʱ����������ǣ�������ң��");
				tell_object(me, "$HIC��ɽ�������ϳ��ֳ�һƬ�������ɫ��\n");
				liqiouheng->add_temp("xy/daoluan1",1);
				liqiouheng->call_out(do_daoluan1, 300);	
				break;
			case 1:
				tell_object(me, "\n$HIC��Ȼ�������������������Թ���ࡣ");
				tell_object(me, "$HIC�·�һ��ʧ������Ů�����������ĵ����£�ʧ�⡢���塢���λ�����ʹ��");
				tell_object(me, "$HIC��ɽ���ѱ��еİ�����Ȼ�����Щ���ҡ�\n");
				liqiouheng->add_temp("xy/daoluan1",1);
				liqiouheng->call_out(do_daoluan1, 300);	
				break;
			case 2:
				tell_object(me, "\n$HIC��Ȼ��������һ�䡣");
				tell_object(me, "$HIC������ޣ��ն������г�����һ�ж��ƹ���ȥ�̣���û��ʲô��ֵ��������һ�������ҵĸо�Ϯ����ͷ��");
				tell_object(me, "$HIC��ɽ���ѡ��ۡ���һ���³�һ����Ѫ���漴����ص��ڵ��ϡ�\n");
				destruct(liqiouheng);
				me->set("xy/renwu_lost",1);//����ʧ��
				me->move(load_room("��ң��СϪ��"));
				break;
			}
		}
		else
		{
			destruct(liqiouheng);
		}
	}
}

static void do_daoluan2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * liqiouheng = (CChar *)ob;
	if(liqiouheng->querystr("owner1")[0])
	{
		CUser * me=find_online(liqiouheng->querystr("owner1"));
		if(me)
		{
			switch(liqiouheng->query_temp("xy/daoluan2"))
			{
			case 0:
				tell_object(me, "\n$HICһ������͸������谭���˽�����");
				tell_object(me, "$HIC��ʦ梣�ʦ梣���������ﰡ��С��������ý�������˵����ÿ����Ϧ���Ӷ�������������������ȴ������������ǲ���̫�������𣿡�");
				tell_object(me, "$HIC��������ϸ֮������ÿһ���ֶ����������쳣��ȴ�����������˭��\n");
				liqiouheng->add_temp("xy/daoluan2",1);
				liqiouheng->call_out(do_daoluan2, 120);	
				break;
			case 1:
				tell_object(me, "\n$HIC�������ϸ������������չ�������");
				tell_object(me, "$HIC�����梣���ǲ��ǵ���ң��ʦ�簡������������С��ͬס����ߧ���У�������������м���Ҫ��������Ҫ����˵����");
				tell_object(me, "$HICһ���������ǰʦ��ͬ��ѧ��ʱ���龳��һ���˵��ң�Ӷ���������Ŀ̹ǵ��మ��");
				tell_object(me, "$HIC�漴�ƿڴ������ɽ����˵�������µ�һ�����񶾡������޳ܵļ�Ů�ˡ�");
				tell_object(me, "$HIC�漴�ƿڴ������ɽ����˵�������µ�һ�����񶾡������޳ܵļ�Ů�ˣ�˵���Ƕ�����ң�ӱ��������Ļ���");
				liqiouheng->add_temp("xy/daoluan2",1);
				liqiouheng->call_out(do_daoluan2, 120);	
				break;
			case 2:
				tell_object(me, "\n$HICͻȻ֮�䣬����������������֮����˵����");
				tell_object(me, "$HIC����ʦ�磬�㱧ס�ң��ţ������ٱ���Щ�������ң����������");
				tell_object(me, "$HICֻ������ɽ���ѡ��ߡ���һ����ŭ��������ˣ���");
				tell_object(me, "$HICȴ��������۵��������ﲻ�ϴ�������������ң�ӻ���֮�ǡ�");
				tell_object(me, "$HIC��������ɽ���Ѵ�Ϣ���أ�������������ˣ�ʦ�ܴ���û����ϲ���㣬������޳ܹ��������ò�Ҫ������\n");
				liqiouheng->add_temp("xy/daoluan2",1);
				liqiouheng->call_out(do_daoluan2, 120);	
				break;
			case 3:
				tell_object(me, "\n$HIC��ɽ������������һ����Ѫ���漴����ص��ڵ��ϡ�\n");
				destruct(liqiouheng);
				me->set("xy/renwu_lost",1);//����ʧ��
				me->move(load_room("��ң��СϪ��"));
				break;
			}
		}
		else
		{
			destruct(liqiouheng);
		}
	}
}

static void do_daoluan3(CContainer * ob, LONG param1, LONG param2)
{
	CChar * liqiouheng = (CChar *)ob;
	if(liqiouheng->querystr("owner")[0])
	{
		CUser * me=find_online(liqiouheng->querystr("owner"));
		if(me)
		{
			tell_object(me, "\n$HICֻ�������������ʮ���¾��죬��������һ�㣬�ڴ���Ǿ���1�Ǳߴ���������");
			tell_object(me, "$HIC�����ϸ����������ʦ梣����ҵ��������ѽ�������������������ˣ���\n");
		}
		else
		{
			destruct(liqiouheng);
		}
	}
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CUser * me=find_online(querystr("owner"));
		if(me)
		{
			me->set("xy/renwu_lost",2);
			me->move(load_room("��ң��СϪ��"));
		}
	}
	CNpc::die();
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan7"))
	{
	case 0:
		tell_object(me, "\n��ɽ��������һ�Ե�ʬ�壬����ҧ���侱���Ͽ�����Ѫ�����ڹ��������");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "�漴��ϥ���£�����ʳָָ�죬����ʳָָ�أ����кٵ�һ�����ǿ����������������������");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "������ɽ���ѱ����³����İ�����ס���Դ���Χ�����Ʋ�ɢ������������Ũ����Ϊһ�Ű���������Ŀ����û�ˡ�");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 3:
		tell_object(me, "����ֻ������ȫ��ǽڸ�����죬���籬�����������ã����������ὥϡ���������Ű���Ҳ�������ˡ�");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 4:
		tell_object(me, "����ɽ���ѱǿ��в�������������ð�����������ɽ��������˫�ۣ�����վ��");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 5:
		tell_object(me, "\n��ʱ��ɽ�����Ѿ���ȫ�ָ�Ϊ���˰�߰���ֻ������ɫ���ޣ��۲�ӯӯ������ò������������۰�ֺ���Ҳ�ѹ�����ۻ���˼ɵ���ɽ���ѻָ����ա�");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 6:
		tell_object(me, "\n��ɽ����վ��������");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 7:
		tell_object(me, "��ɽ���Ѷ��ž��ӣ���ӯ��ת��һ��Ȧ��");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 8:
		tell_object(me, "��ɽ���Ѳ�֪�뵽��ʲô�������ϸ�����������ƣ����΢΢���¶�������۵�΢Ц��");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 9:
		tell_object(me, "��ɽ���Ѻ�Ȼ��ʶ��һ�Ի������ڣ���������Ц�ݶ���˵����");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 10:
		tell_object(me, "����ζ��ʦֶΪ�һ���������Ϊ����������һʽ��ɽ��÷�֣���");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 11:
		tell_object(me,"\n$HIR����������ɽ���ѽ��⡰��ɽ��÷�֡��ľ�Ҫ���ڣ��ԡ���ɽ��÷�֡����˸���һ��ε���⡣");
		if(me->query("xkd/xy")<10)
		{
			switch(random(3))
			{
			case 0:
				me->add("skill_pro/���չ�/��ɽ��÷��/force",1);
				tell_object(me,"$HIR�����ɽ��÷������ڹ������ڻ��ͨ�ˡ�");
				break;
			case 1:
				me->add("skill_pro/���չ�/��ɽ��÷��/dodge",1);
				tell_object(me,"$HIR�����ɽ��÷��ʹ�õø��ӵ���Ӧ���ˡ�");
				break;
			case 2:
				me->add("skill_pro/���չ�/��ɽ��÷��/damage",1);
				tell_object(me,"$HIR�����ɽ��÷�����������ˡ�");
				break;
			}
		}
		else
		{
			//ʮ��������ɺ󣬴�����ɽ��÷���µľ��а׺��ƾ�
			me->set("pro/skill/zhemei_shou",1);
			tell_object(me,"$HIR���Ȼ����������Σ����ֻû�������÷�������������$HIY����ɽ��÷�֡�$HIR��߾������$HIY��÷����Ū��$HIR��");
		}
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 12:
		tell_object(me, "\n��ɽ���ѴҴҵ��뿪�ˡ�");
		me->delete_temp("xy/tanhuan7");
		me->set("xy/renwu8",1);//��ң����ڰ˲��֣�ҽ�������
		me->enable_player();

		CContainer * env=me->environment();
		CContainer * Xy_Npc=env->present("tong lao");
		if(Xy_Npc)
			destruct(Xy_Npc);
		break;
	}
}

NPC_END;




