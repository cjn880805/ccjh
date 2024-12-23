//xy_xiaoyaozi1.h ��ң�ӣ���ߧ���أ�
//�ز� 2002��12��12

NPC_BEGIN(CNxy_xiaoyaozi);

virtual void create()
{    
    set_name("��ң��", "xiaoyao zi");
    set("long","ֻ�����촽ī����������񣬾���Ͷ��֮����ɷ��������ţ�ֱ������ң�������ֵ����쾡�¡�");	
    set("title","��ң��");
	set("gender", "����"); 
    set("age", 23);

    set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 32);
    set("per", 40);

    set("icon",13);
	create_family("��ң��", 1, "����");

    set("max_hp", 28000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 80); 
    set("combat_exp", 90000000); 
	
	set("no_kill",1);

    set_skill("force", 400);
    set_skill("beiming_shengong", 400);
    set_skill("dodge", 400);
    set_skill("lingboweibu", 400);
	set_skill("xiaoyao_bu", 400);
    set_skill("unarmed", 400);
    set_skill("liuyang_zhang", 400);
    set_skill("parry", 400);
    set_skill("blade", 400);
    set_skill("xiaoyao_dao", 400);
    set_skill("zhemei_shou", 400);
    set_skill("hand", 400);
	set_skill("lingxiao_kuaijian", 400);
	set_skill("xiaoyao_jian", 400);
	set_skill("sword", 400);
	set_skill("literate", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "lingxiao_kuaijian");
    map_skill("blade", "xiaoyao_dao");
	map_skill("sword", "xiaoyao_jian");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");

    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("changjian")->wield();
	set("no_huan",1);

}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("xy/renwu5") && !me->query("xy/renwu5_1") )
	{
		if(me->query_skill("xiaoyao_jianfa",1)<300)
		{
			tell_object(me, "\n$HIR��ң�Ӷ���˵������Լ������������������ž�ѧ��ң�����ݴ����㣬�ɹ���񣬾�ȫƾ�㷢���ˣ���");
			tell_object(me, "\n$HIR��ң��Ϥ�����㽲����һЩ��ң�����ı仯��Ҫ��");
			tell_object(me, "$HIR��ң����ס���˫�����ţ���һ���೤���ھ��������޵ض��˸��㡣");
			tell_object(me, "$HIR��ֻ��������������һЩ΢��ı仯��");
			tell_object(me, "\n$HIR��ң�Ӷ���˵����������������ͥ��Լ��ͽ����������ʰҲ��������ɣ���");
			me->set_skill("xiaoyao_jianfa",300);
			me->FlushMySkill(me);
		}
		else
		{
			tell_object(me, "\n$HIR��ң�Ӷ���˵������Լ������������������ͥ��Լ��ͽ����������ʰҲ��������ɣ���");
		}
		me->set("xy/renwu5_1",1);//�����ʱ���300����ң����
		
		move(load_room("temp_xy"));
	}
	else if(me->query("xy/renwu4") )
	{
		if(me->query("xy/renwu4_51") && me->query("xy/renwu4_52") && me->query("xy/renwu4_53")
			&& me->query("xy/renwu4_54"))
		{
			say("��ң�ӵ�����Ϊʦ��Ȼû�п����ˣ�����������ʱ�����꣬����ͽ���ڶ̶���������ȥ�������⼸��������ΪҲ���г�����������˾�����ѵĶ�Լ��������ʤ���ˣ���",me);
			say("��ң����Ц��Ц�ؿ����������ͽ�����������еõ���������ָ����Ϊʦ����ʮ��ϲ��������",me);
			me->set("xy/renwu4_5",1);
			SendMenu(me);
			CContainer * Xy_Npc;
			CContainer * env=me->environment();
			if(me->query("xy/renwu4_4")==1)
			{
				Xy_Npc=env->present("tong lao");
				if(Xy_Npc)
					destruct(Xy_Npc);
			}
			else if(me->query("xy/renwu4_4")==2)
			{
				Xy_Npc=env->present("li qiou heng");
				if(Xy_Npc)
					destruct(Xy_Npc);
			}
		}
		else
		{
			char msg[255];
			if(! strlen(ask))
			{
				if(!me->query("xy/renwu4_2"))
					AddMenuItem("����ң�ӱ�ʾ��л","thx",me);
				else if(me->query("xy/renwu4_2") && !me->query("xy/renwu4_3"))
					AddMenuItem("����ң��Ϊʦ","baishi",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "thx") )
			{
				say(snprintf(msg, 255,"��ң��˵������֮ǰ˵������%s�β�֮��Ҳ�Ǵ���һ��˽�ģ����ھ�Ҫ˵���ˣ�Ӧ�����ȫƾ�����������Ҿ�����ǿ����",query_respect(me)),me);
				AddMenuItem("ͬ��","yes",me);
				AddMenuItem("��ͬ��","no",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "yes") )
			{
				//��������
				me->disable_player("������");
				me->call_out(do_tanhua, 1);
			}
			else if(!strcmp(ask, "no") )
			{
				say(snprintf(msg, 255,"��ң��˵������%s���Ѿ��������Ե�����ǿ�󡣡�",query_respect(me)),me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "baishi") )
			{
				say(snprintf(msg, 255,"��ң�ӵ������Ҽ�%s�����ļѣ��ҹ�������ʴ�������ͽ���Ը�����֮��Լ�������Ӧ�����������г�л������ʳ�ԡ���",query_respect(me)),me);
				AddMenuItem("ͬ��","y",me);
				AddMenuItem("��ͬ��","n",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "y") )
			{
				if(DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
				{
					say("��˵��������ʮ����Ľ��ң��ǰ�����书���绪������Ҳ���ܱ��ѱ��Ŷ�ʦ��",me);
					say("��ң��΢΢һ㶣�����ʮ���ź���������˵��������ˣ��ұ�����Ϊ����������Σ������ҿɴ��㼸ʽ��ң�������ȱ��Խ����������ջء���Ȼ���³�֮���ұ��в�������",me);
					me->set("title","��ң�ɼ�������");
				}
				say("���ϲ֮����ȻӦ�ʡ�",me);
				say("��ң�ӺǺ�Ц�������벻�������յô˼�ͽ���������ø����Ǵ���ϣ���ˣ���",me);
				SendMenu(me);
				me->disable_player("������");
				me->call_out(do_tanhua1, 5);
			}
			else if(!strcmp(ask, "n") )
			{
				say(snprintf(msg, 255,"��ң��˵������%s���Ѿ��������Ե�����ǿ�󡣡�",query_respect(me)),me);
				SendMenu(me);
			}
			else
			{
				if(me->query("xy/renwu4_3"))
				{
					say("ͽ��������ǰ���ᱦ���ȿ�ĥ������������ǻۡ��书��Ҳ���������ʵս���顣",me);
					say("�������̫Σ�գ��������������ʦ�壬������ʦ��������",me);
					SendMenu(me);
				}
			}
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	switch(me->query_temp("xy/tanhuan6"))
	{
	case 0:
		tell_object(me, "\n��ң�ӻ�����˵�������¡�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "\n�����ǰ����ң����ֿ��˾������һͬ��ɽ��ˮ��;�������ڣ���������������������������������");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, "��һ�գ���������ɽ��ĺ�ɽ��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ�����������������ӵ�����һ�����ٲ��Ӹ�����ֱк��ȥ��");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "\n��ң�Ӻ����������Ȼһ����Х���������ʣ�ʹ��������һ����ң�����ڸ��±��������������г���������");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "\n$HIY����ˮ�¾����ޣ�����Ҳ�Ե�ָ�ϡ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "$HIYɲ�Ƿ���ͬһ�Σ��񻷷���Գ�����");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, "$HIY�������޻����٣����ղ�������ң��");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me, "$HIY��������빲�����ͬЦ�������");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me, "\nȴ���ϣ�������ʱ����Щ�ƣ���ʱ��ɽ��һ��������һ�Σ�����ʧ�����ɽ�¡�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me, "˾��������ٶ��£������˽���δ������ң�ӡ���ϸ����Χ�����������ͺ�һ���ɡ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me, "ֻ�����ɽ����һ�����ٲ����������գ��������£�����һ���峺�쳣�Ĵ��֮�С�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 11:
		tell_object(me, "���ٲ�����ע�룬��ˮȴ�����磬��������йˮ֮����");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 12:
		tell_object(me, "�ٲ�ע�봦��ˮ������ֻ����ٲ�ʮ���ɣ���ˮ��һƽ�羵������������У�����Ҳ��һ�����Բ�¡�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 13:
		tell_object(me, "\n��ң������֮�£����һ�����ã������������Ծ�ʯ����һ�ơ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 14:
		tell_object(me, "$HIC������¡¡һ����죬���¶��һ���������ߵĶ�Ѩ��");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;	
	case 15:
		tell_object(me, "$HIC����֮�£�˭Ҳûȥ���붴������Σ�գ���һ���߽���ȥ�� ");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 16:
		tell_object(me, "�߹�һ������������ɽ������Ȼ������һ���ɶ��칤�ĵ���ʯ�ң���Ϊ$HIR��ߧ����$COM��Ҳ��֪�Ǻ��������� ");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 17:
		tell_object(me, "���ڲ������ᣬ�����Ѱ���������ѧ֮��ȫ��");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 18:
		tell_object(me, "\n���˾�Ϊ��գ������龰��ȻȸԾ���ѡ�Ȼ����ϲ�����뼰$HIR��ߧ����$COM�Ĺ������ǣ���������Щ���Ρ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 19:
		tell_object(me, "���˶����ף��˴���Ϊֿ�ѣ���ϰ��֮�ˣ�����ѧʤ����������ʱ���޻�������֮��");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 20:
		tell_object(me, "Ȼ������������һ�ˣ�Ϊ�������Ѻ�����˾��������������֮���ñ˴˵�ͽ�ܽ��б��ԣ��Զ�$HIR��ߧ����$COM�����ˡ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 21:
		tell_object(me, "����Լ����ͽ�ܱ�����ȫʹ�ñ����书���������������ڼ䣬˭Ҳ����̤��$HIR��ߧ����$HIC�벽��");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 22:
		tell_object(me, "\n����˾�������ڸ���������һ�����ۣ�ȡ��׷�¹ۣ��Ժ�׷��ɢ�ˣ�����һͽ��磬Ϥ�Ĵ��ڡ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 23:
		tell_object(me, "\n��ң�Ӵ�˼����®������λʦ��ü�������ңŮһ���������������Сͽ�����ӵ�Ҳ������Ȼ�Եá�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 24:
		tell_object(me, "\n��ʵ��ң��Ҳ���ף��˶�Լ�������в���������ң�ɵ��书��Ȼ���ȴ�輫�ߵ����������������д�ɡ�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 25:
		tell_object(me, "����ң�����Ի�Ҳ��Ϊ����ÿ���￴����ͽ�������Ե����֡�");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 26:
		tell_object(me, "Ȼ����֮Լ��������ң��Ҳ���Ⱗ̾�����������ѻ�������");
		me->add_temp("xy/tanhuan6",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 27:
		tell_object(me, snprintf(msg, 255,"\n��ң�ӵ������Ҽ�%s�����ļѣ��ҹ�������ʴ�������ͽ���Ը�����֮��Լ�������Ӧ�����������г�л������ʳ�ԡ���",query_respect(me)));
		me->delete_temp("xy/tanhuan6");
		me->set("xy/renwu4_2",1);//����ң��Ϊʦ
		me->enable_player();
		break;
	}
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan7"))
	{
	case 0:
		tell_object(me, "\n��ң�ӵ���ͽ����ѧ�������ǲ��Ȼ�ٵо�������Ƿȱ��");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "��ȥ������ʮ������������������׻������䡢��ȸ��ͳ����������");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "�����߲㣬ÿ�����������һ�Ϲ�װ�������ɸ��������ػ���װ�����������Ե���ֻҪ��սʤ�����߾Ϳɻ����Ӧ��װ����");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 3:
		tell_object(me, "Ȼ����ʱ�����꣬װ����Ȼ�������У��������ڻ������أ�������֣�ͬʱ��λ�������ߵ��书���黯��Ҳ����Ҫԭ��");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 4:
		tell_object(me, "ͽ��������ǰ���ᱦ���ȿ�ĥ������������ǻۡ��书��Ҳ���������ʵս���顣");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 5:
		tell_object(me, "�������̫Σ�գ��������������ʦ�壬������ʦ��������");
		me->add_temp("xy/tanhuan7",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 6:
		tell_object(me, "������������ͬ�ţ�����ѧ���򲻾���ͬ�����ܵ�����ָ�㣬������Ǵ������档");
		me->delete_temp("xy/tanhuan7");
		me->set("xy/renwu4_3",1);//Ѱ���������б���
		me->enable_player();
		break;
	}
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!me->querymap("xy")) return 0;

	if(EQUALSTR(ob->querystr("name"), "������ָ��") && EQUALSTR(ob->querystr("base_name"), "xuanwu_huan") 
		&& me->query("xy/renwu4_5") && !me->query("xy/renwu4_61") && !me->query("xy/renwu5"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
		{
			tell_object(me,"\n$HIR��ң�ӹ�����Ц�������ã��ã���ͽ����������������Ҳ��Ϊʦ���Ҳ��һöָ������Ȼģ����ª��һ�㣬Ҳ��Ϊʦһ�����⣬�м�Ī��Ī������");
			tell_object(me,"��ң�Ӹ���һö$YEL��ɫ��ָ��$COM��");
			load_item("heise_huan")->move(me);
		}
		else
		{
			tell_object(me,"\n$HIR��ң�ӹ�����Ц�������ã��ã���ͽ����������������Ҳ��Ϊʦ��ָ���㼸���书�ɣ���");
			tell_object(me,"�õ���ң�ӵ�ָ�㣬�����ѧ����������1000�㣡");
			me->add("combat_exp",1000);
			me->UpdateMe();
		}
		me->set("xy/renwu4_61",1);//������ָ���͸���ң��
		
		if(me->query("xy/renwu4_4")==1)
		{
			tell_object(me,"\n$HIR��ң��΢Ц�Ŷ���˵���������ʦ���⼸������ᱦ��Ҳ�������࣬���Ƿ�ҲҪ������ʾ��л�أ���");
		}
		else if(me->query("xy/renwu4_4")==2)
		{
			tell_object(me,"\n$HIR��ң��΢Ц�Ŷ���˵���������ʦ���⼸������ᱦ��Ҳ�������࣬���Ƿ�ҲҪ������ʾ��л�أ���");
		}
		destruct(ob);
		return 1;
	}

	return 0;
}
NPC_END;




