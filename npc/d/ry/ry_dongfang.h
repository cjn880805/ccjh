//dongfang.h
//code by zwb
//12-16
//inherit F_MASTER;

ZUSHI_BEGIN(CNry_dongfang);

virtual void create()
{

	set_name("��������","dong fang");

    set("nickname",  "�����޵�" );
    set("title", "������̽���");
    set("gender", "����");
    set("shen_type", -1);
    set("age", 42);
    set("long","������������̽������ų����˿ɵУ������֪��Ϊʲô����Ϊ��������������");
    set("attitude", "peaceful");
 	set("icon",old_man2);

    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("hp", 22000);
    set("max_hp", 22000);
    set("mp", 16500);
    set("max_mp", 16500);
    set("mp_factor", 400);

    set("combat_exp", 52500000);
    
    set_skill("force", 250);             // �����ڹ�
    set_skill("hand", 250);            // ����ָ��
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("dodge", 250);             // ��������
    set_skill("parry", 250);             // �����м�
    set_skill("sword", 400);             // ��������
    set_skill("pixie_jian", 350);        // ��а����
    set_skill("changquan", 280);         // ̫�泤ȭ
    set_skill("literate", 100);          // ����ʶ��
    set_skill("kuihua_xinfa", 250);      // �����ķ�

    map_skill("force", "kuihua_xinfa");
    map_skill("sword", "pixie_jian");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");

    create_family("�������", 2, "����");

    carry_object("xiuhua")->wield();
    carry_object("yan_dress")->wear();
	if (random(3)==0)
		carry_object("heiyugao");

	set("apply/armor", 380);
    set("apply/damage", 200);

	set("no_kill",1);
	set("no_���־�",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	
	set("bigboss",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query_temp("ry/renwu4_1")  && !me->query_temp("ry/renwu4_2")) 
	{
		tell_object(me,"\n$HIR��������������û�뵽�㾹Ȼ�ܴ����������������ջ���ɱ���������ˣ���ֻ���Ƚ���������������⡸����ȥ�������꡹�ˡ���");
		tell_object(me,"$HIR����������������ϧ��ϧ������һ����书����ȴҪ�������֡���\n");
		me->set_temp("ry/renwu4_2",1);//���ľ�ս����ս��������
		set("owner",me->id(1));
		this->kill_ob(me);
	}
}


virtual void die()
{
	if(querystr("owner")[0])
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me)
		{
			if(me->query_temp("ry/renwu4_2")  && EQUALSTR(querystr("owner"), me->id(1)))
			{
				char msg[255];
				me->delete_temp("no_fei");
				me->add("xkd/ry",1);//����������񣺲�������ɵ�����
				me->set("ry/jq",me->query("age"));//����һ��ֻ����һ��

				tell_object(me, "\n$HIC��������������������������û�뵽������û�뵽����");
				tell_object(me, "$HIC�����������������ڶ���Ҽ���ʱ���ҾͿ��������Ȿ���������䡷���װ��ˣ���ʱ���ս������ҵĶ��֡�����\n");
				g_Channel.do_channel(&g_Channel, 0, "news", 
					snprintf(msg, 255, "$HIC%s����%s(%s)$HIY�������죬������ľ�´��$HIC������̽���$HIY����������$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));

				int exp=int(me->query("age")*me->query("level")*0.87);
				if(exp<3000)
					exp=2000+random(3000);
				int repute=random(int(exp/2))+exp;
				if(me->query("repute")<0)
					repute=-repute;
				me->add("repute",repute);

				if(DIFFERSTR(me->querystr("family/family_name"), "�������"))
				{
					me->add("combat_exp",exp);
					g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIC%s���$HIY%d$HIC��������齱����ͬʱ�����%d��Ľ���������\n$COM",me->name(1), exp,repute));
					message_vision (snprintf(msg, 255, "$HIR$N�����%d�������齱����ͬʱ�����%d��Ľ���������",exp,repute),me);
				}
				else
				{
					CContainer * bot = load_item("kuihua_pro");
					bot->set("owner",me->id(1));
					bot->set("time",24);
					bot->move(me);
					me->add("combat_exp",exp);
					message_vision (snprintf(msg, 255, "$HIR$N�����%d�������齱����ͬʱ�����%d��Ľ�������",exp,repute),me);
					g_Channel.do_channel(&g_Channel, 0, "new", snprintf(msg, 255, "$HIC%s���$HIY%d$HIC��������齱����һ��$HIY���������䡷���װ�$HIC��ͬʱ�����%d��Ľ���������\n$COM",  me->name(1),exp,repute));
					g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)����ˡ��������䡷���װ档", me->name(1),me->id(1)));
				}
			}
		}
	}
	CNpc::die();
}


ZUSHI_END;