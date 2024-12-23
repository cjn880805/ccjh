//xy_tielao.h	��ɽͯ�ѣ����꣩
//�ز� 2002��12��2

NPC_BEGIN(CNxy_tielao);

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

	set("hp", 20000);
	set("max_hp", 20000);
	
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 100);

	set("combat_exp", 95000000);
	set("chat_chance", 30);

	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
    set_skill("sword",300);
	set_skill("literate", 250);

	set_skill("zhemei_shou",300);
	set_skill("liuyang_zhang",300);
	set_skill("yueying_wubu",300);
	set_skill("bahuang_gong", 300);
	set_skill("xiaoyao_jian", 300);

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

	set("apply/armor", 100);
    set("apply/damage", 50);

	set("no_kill",1);
	set("no_huan",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * env=me->environment();
	if((EQUALSTR(env->querystr("base_name"), "��ң��ľ��" )))
	{
		if(me->query("xy/renwu7") && !me->query("xy/renwu7_1")
			&& !me->query_temp("xy/renwu7_1")&& !is_fighting()) 
		{
			me->set_temp("xy/renwu7_1",1);//��ɽ�����������������
			tell_object(me,"\n$HIR��ɽ��������ɫ���ǵ����ض��Ų����������������üëһ��ƺ���Ҫ˵ʲô��");
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if((EQUALSTR((me->environment())->querystr("base_name"), "��ң��ľ��" )))
	{
		if(me->query("xy/renwu7") && !me->query("xy/renwu7_1") )
		{
			if(! strlen(ask))
			{
				AddMenuItem("������������","xinshi",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "xinshi") )
			{
				say("��ɽ���ѵ����������������˻�����Ψ�Ҷ��𹦡������������ͬ��ͯ��������ʦ������ʼ���Ǿ��మ�١���",me);
				say("��ɽ���ѵ����������ҵ��񹦼�����ɡ����ҹ���֮�գ�������Ҳ�����ָ��������˰�ģ������ʱ������ʱ������",me);
				say("��ɽ��������������ʲô�����ϸ���һƬ糺졣",me);
				say("��ã���ɽ���ѲŻع��������Դ����ߵ�����һЦ������˵������ֻ���񹦵����һ�㼫����ϰ���ұ���չ��������귽�ɡ���",me);
				say("��ɽ���ѵ������չ�֮ʱ���ճ��öȣ������������ϣ�������˴��ţ����û��һ�������Ļ������������ѳɣ�����������Ҳ���Իָ��ˡ���",me);
				say("��ɽ���ѵ�������������Ҫ��һ����Ϊ���عأ�ʦֶ�Ƿ�Ը������һ��֮������",me);
				AddMenuItem("Ը��","yes",me);
				AddMenuItem("��Ը��","no",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				me->disable_player("������");
				me->call_out(do_tanhua, 1);
			}
			else if(!strcmp(ask, "no") )
			{
				say("��ɽ����¶����ʧ�������飬��̾һ����Ҳ�����������ת����ȥ��",me);
				SendMenu(me);
			}
			return 1;
		}
		else if(me->query("xy/renwu4_3") && ! me->query("xy/renwu4_61"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("���빲ͬ�ᱦ","duobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "duobao") )
			{
				say("������ɽ����˵������������ǰ���������ᱦ����������ǳ�����������ܼ�����֪ʦ���ɷ���������",me);
				if((!me->query("xy/renwu4_4") ||me->query("xy/renwu4_4")==1 ) && !me->query_temp("xy/renwu4_1"))
				{
					say("��ɽ����˵�������ðɣ��ұ�����ȥһ�ˣ���",me);
					tell_object(me,"$HIC��ɽ���Ѿ�����ʼ�������ж���");
					set_leader(me);
					set("owner",atoi(me->id(1)));
					me->set_temp("xy/renwu4_1",1);//������ɽ���ѳɹ�1����ɽ���� 2�������
					if(!me->query("xy/renwu4_4"))
						me->set("xy/renwu4_4",1);	//������ɽ����ǰȥ�ᱦ��1����ɽ���� 2�������
				}
				else if(me->query_temp("xy/renwu4_1"))
				{
					say("��ɽ����������üͷ��",me);
				}
				else
				{
					say("��ɽ���Ѳ��õ���������ȥ���������Ǹ���һ��ĥ���Ļ��ᣬ������ʦ���ö�����������,�㻹ĥ��ʲô�أ���",me);
				}
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual char * chat_msg()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(!me)
		{
			destruct(this);
		}
		else if(me->query("xy/renwu4_4")==1 && me->query_temp("xy/renwu4_1")==1)
		{
			
			if(me->query_temp("fight/is_fighting") 
				&& EQUALSTR(((me->environment())->environment())->name(1),(environment())->name(1)))
			{
				int team;
				CFightRoom * obj=(CFightRoom *)me->environment();
				if(me->query_temp("fight/fight_team"))		//����A��
					team = 1;
				else
					team = 0;
				move(obj);
				obj->Join_Team(this, team);
			}
		}
		else
		{
			destruct(this);
		}
	}
	return 0;
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(me)
		{
			if(me->query("xy/renwu4_4")==1 && me->query_temp("xy/renwu4_1")==1)
			{
				me->delete_temp("xy/renwu4_1");
			}
		}
	}
	CNpc::die();
}

virtual int accept_object(CChar * me, CContainer * ob)
{

	if(EQUALSTR(ob->querystr("name"), "��ȸ��ң��") && EQUALSTR(ob->querystr("base_name"), "zhuque_jin") 
		&& me->query("xy/renwu4_61") && !me->query("xy/renwu4_62") && me->query("xy/renwu4_4")==1
		&&!me->query("xy/renwu5"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
		{
			tell_object(me,"\n$HIR��ɽ���ѺǺ�Ц��������лʦֶ�ˣ���������Һ�ϲ����������ʹ���һʽ��÷����Ϊл��ɣ���");
			tell_object(me,"\n$HIR�����������ѽ��⡰��÷�֡��ľ�Ҫ���ڣ��ԡ���÷�֡����˸���һ��ε���⡣");
			switch(random(3))
			{
			case 0:
				me->add("skill_pro/���չ�/��÷��/force",1);
				tell_object(me,"$HIR�����÷������ڹ������ڻ��ͨ�ˡ�\n");
				break;
			case 1:
				me->add("skill_pro/���չ�/��÷��/dodge",1);
				tell_object(me,"$HIR�����÷��ʹ�õø��ӵ���Ӧ���ˡ�\n");
				break;
			case 2:
				me->add("skill_pro/���չ�/��÷��/damage",1);
				tell_object(me,"$HIR�����÷�����������ˡ�\n");
				break;
			}
		}
		else
		{
			tell_object(me,"\n$HIR��ɽ���ѺǺ�Ц��������лʦֶ�ˣ���������Һ�ϲ�����������ָ���㼸ʽ�书�ɣ���");
			tell_object(me,"�����������ѵĽ��⣬����ѧ�������˸���һ��ε����,����������1000��ľ��顣��");
			me->add("combat_exp",1000);
			me->UpdateMe();
		}
		me->set("xy/renwu4_62",1);//��ȸ��ң���͸���ɽ����
		me->set("xy/renwu5",1);//��ң����������岿�֣�������ߧ����
		destruct(ob);
		return 1;
	}

	return 0;
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	CContainer * XyNpc;
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me,"\n$HIC��ɽ����¶���˿�����΢Ц�����ã��Ǿ�����ʦֶ�ˣ�������һͬȥ�չ��Ұɣ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me,"\n$HIC������������ɽ���ѳ�����һ����������ۡ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me,"\n$HIC����۲�������ض���ɽ����˵������Ӵ����ϲʦ�㼴�������񹦣�����Ҫ�����꣬��ĺ�����Ŷ��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me,"$HIC����������ʦ�����������������������ÿ����Ϧ��ʱ��С���Ҿ�ȥ�չ��ҿ���ʦ�㣬Ϊʦ���ⷦ�ơ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me,"$HICʦ����˵�ò��ð�����");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me,"\n$HIC��ɽ�����ƺ�һ�����������Ǹ������꣬�㵱�Ҳ�֪�㰲��ʲô���𣡡�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me,"$HIC��ɽ���������㣬�ɿ���߳�����ң�ȡ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me,"\n$HIC���������ۿ����Ľ�Ц������ʦ����ô��ôС���أ�С���ҿ��ǳ���ҪΪʦ������أ�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me,"$HIC��ʱ����ʦ�㲻��ӭ�ң��ҿ���ҲҪȥŶ����");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me,"\n$HIC��ɽ���Ѻ���չ�������Ṧ��һ·�ɱ�������ʱ��֮��������˴���ش���");
		me->add_temp("xy/tanhuan",1);
		me->move(load_room("��ң�ȴ���Ǿ���1"));
		XyNpc=env->present("tong lao");
		if(XyNpc)
			((CChar *)XyNpc)->move(load_room("��ң�ȴ���Ǿ���1"));
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me,"\n$HIC��ɽ���Ѷ���˵���������Ƚ�ȥ�ڱչ��ҵ��㣬��Щ����һ�ỹҪ������ϸ˵˵����");
		tell_object(me,"$HIC˵�գ�һ�������˽�ȥ��\n");
		me->delete_temp("xy/tanhuan");
		me->set("xy/renwu7_1",1);//��Ӧ����ɽ���ѻ���
		me->enable_player();
		XyNpc=env->present("tong lao");
		if(XyNpc)
			destruct(XyNpc);
		break;
	}
}

NPC_END;




