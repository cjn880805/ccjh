//xy_xiaoyaozi1.h ��ң�ӣ���ߧ���أ�
//�ز� 2002��12��12

NPC_BEGIN(CNxy_xiaoyaozi1);

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

}

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * env=me->environment();
	if((EQUALSTR(env->querystr("base_name"), "��ң����ߧ����ʯ��3" )))
	{
		CContainer * XyNpc;
		if(me->query_temp("xy/renwu6_5"))
			XyNpc=env->present("li qiou heng");
		else
			XyNpc=env->present("li cang hai");
		if(XyNpc && me->query("xy/renwu6") && !me->query("xy/renwu7") && !is_fighting()) 
		{
			if(me->query_temp("xy/renwu6_5")&& me->query_temp("xy/renwu6_6"))
			{
				me->disable_player("������");
				me->call_out(do_tanhua1, 1);
			}
			else if(me->query_temp("xy/renwu6_4"))
			{
				me->disable_player("������");
				me->call_out(do_tanhua, 1);
			}
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	switch(me->query_temp("xy/tanhuan"))
	{
	case 0:
		tell_object(me, "\n��ң�ӿ�����׺����������������´�����һ�飬Ȼ����е��ʵ�����Сʦ�ã�����ô�����ˣ������ʯ����û�������㣡��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 1:
		tell_object(me, "��׺�Ц���������ⲻ�Ǻúõ�������ĸ�ͽ���ݣ�����ô���������أ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 2:
		tell_object(me, "��ң�Ӱ�����˵������������ѽ���������Ҳ��ģ�Ҫ����������ʦ��һ���ú�ѧһ�����Ҳ��Ϳ���ʡ�Ķ��ˣ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 3:
		tell_object(me, "\n��׺���Ƥ��˵������ʦ�ֽ���ѧ�������в�ѧ֮����");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 4:
		tell_object(me, "˵�գ��ӵ���ʰ��һ�Ѹյ�������ʯ���ϵ�ͼ������������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 5:
		tell_object(me, "\n��ң��΢Ц������������ĸյ���˵����������Ҫѧ�������ȴӶ���д�ֽ�����ˣ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 6:
		tell_object(me, "��׺����������ѧ�Ǹ���ɶ�ã���Ҫѧ����������...��");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 7:
		tell_object(me, "\n��ң�ӵ�����Сʦ�ô��Բ��죬������ˣ����Ҳ�ǰ��˵У�Ȼ������ѧ�þ��������ǧ�˵С����˵С�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 8:
		tell_object(me, "�ο�����ʶ�ֿ�������������������ѧ��Ҳ���������棬���һ�����дʫ�����鼺���ˣ�ʵ��һ�ٶ�á���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 9:
		tell_object(me, "\n��׺�����ˮ�����˫�ۣ���ԭ������ʶ�ֻ�����Ⱥô�������ʦ���Ƚ�����ʫ�ɣ���");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 10:
		tell_object(me, "\n��ң��Ц��Ц����������������");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 11:
		tell_object(me, "\n$HIY��ɪ�޶���ʮ�ң�һ��һ��˼���ꡣ");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 12:
		tell_object(me, "$HIYׯ�������Ժ����� ���۴����жž顣");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 13:
		tell_object(me, "$HIY�׺����������ᣬ ������ů�����̡�");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;
	case 14:
		tell_object(me, "$HIY����ɴ���׷�䣬 ֻ�ǵ�ʱ���Ȼ����");
		me->add_temp("xy/tanhuan",1);
		me->call_out(do_tanhua, 1);	
		break;	
	case 15:
		tell_object(me, "\n�㿴����׺�רע��ģ�����о�������ţ������ĵ��뿪�ˡ�");
		me->delete_temp("xy/tanhuan");
		me->set_temp("xy/renwu6_5",1);//�������׺�������ߧ���ص�����
		CContainer * env=me->environment();
		CContainer * XyNpc=env->present("li cang hai");
		if(XyNpc)
			destruct(XyNpc);
		me->enable_player();
		load_npc("xy_licanghai1")->move(env);
		break;
	}
}

static void do_tanhua1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	CContainer * XyNpc;
	switch(me->query_temp("xy/tanhuan1"))
	{
	case 0:
		tell_object(me, "\n��׺������Ÿֵ�������ıȻ��ţ�������ʹ�ģ�������ң�书�ľ���--��ң������");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 1:
		tell_object(me, "\n��ң�Ӿ�̾�������벻��Сʦ����˴ϻۣ���ô�̶̼���ʱ��������ѧ����ģ�����ˡ�");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 2:
		tell_object(me, "��ϧ����ң����̫���Ե������������ö��˱���˼�����");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 3:
		tell_object(me, "���ʦ�洫���⵶����˵����ʹ�ô˵����ľ��в��ɳ����ŴΣ��������Ѫ�����߶�������");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 4:
		tell_object(me, "\n��׺���Ƥ��Ц������ʦ�ֶ����Ҵ������ҽ������������������������ң���еı׶ˣ���");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 5:
		tell_object(me, "\n����۽ӿ�˵�������ò�֪�ߵ�С���ӣ���ѧ�˼�ʽ��������亣���ˣ���");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 6:
		tell_object(me, "����۶�����ң��˵������ʦ�֣��������������أ��ɷ����ҳ�ȥһ�ˣ���");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 7:
		tell_object(me, "\n����ۻ�����ң�ӵĸ첲�����ǵ����˳�ȥ��");
		me->add_temp("xy/tanhuan1",1);
		XyNpc=env->present("li qiou heng");
		if(XyNpc)
			destruct(XyNpc);
		XyNpc=env->present("xiaoyao zi");
		if(XyNpc)
		{
			XyNpc->set("del",1);
			(CChar *)XyNpc->move(load_room("temp_xy"));
			XyNpc->call_out(do_die, 60);
		}
		me->call_out(do_tanhua1, 1);
		break;
	case 8:
		tell_object(me, "\n��׺�������վ�����������Ϊ��į��ֻ�����﷭����ȥ�����ţ�");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 9:
		tell_object(me, "���׺����������ᣬ������ů�����̡�");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 10:
		tell_object(me, "����ɴ���׷�䣬ֻ�ǵ�ʱ���Ȼ......��");
		me->add_temp("xy/tanhuan1",1);
		me->call_out(do_tanhua1, 1);	
		break;
	case 11:
		tell_object(me, "\n��׺�ĬȻ��ȥ��");
		me->delete_temp("xy/tanhuan1");
		me->set("xy/renwu7",1);//��ң������߲���������ɽͯ��
		XyNpc=env->present("li cang hai");
		if(XyNpc)
			destruct(XyNpc);
		me->enable_player();
		break;
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("del"))
		destruct(npc);
}

NPC_END;




