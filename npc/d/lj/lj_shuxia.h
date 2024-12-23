//lj_shuxia.h	���չ�����
//�ز� 2002��6��1

NPC_BEGIN(CNlj_shuxia);

void create()
{
	if(random(2))
		set_name("����","dao zhu");
	else
		set_name("����","dong zhu");

	set("title", "���չ�����");
	if(random(2))
	{
		set("gender", "����");
	}
	else
	{
		set("gender", "Ů��");
	}
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",random(53));
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);
	set("no_kill",1);
	set("chat_chance", 80);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");

	call_out(do_die, 1800);
	set("no_kill",1);
	
};



void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("lj/renwu7") && query("lj/sha")) 
	{
		tell_object(me, "$HIR����������ȣ����󵨿�ͽ,�������ɴ�ᵷ�ң����ҽ�Ů�������£���");
		((CUser *)me)->Ready_PK();
		((CUser *)this)->Ready_PK();
		this->kill_ob(me);	
		me->kill_ob(this);
	}
	else
	{
		CContainer * env = me->environment();
		if (!me->query("lj/renwu5")&& !me->query("lj/renwu6")) 
		{
			tell_object(me, "\n$HIC��Ȼ������ֻ��ǰ��¶��һ��ƻ𣬵ƻ𷢳������͵Ĺ�â���Ĳ�ͬѰ���ƻ��ɫ��������ơ�");
			tell_object(me, "$HIC��ʱ�����ﲻ��һ������������аħ������ڴ˾ۻᣬ�һ�������Ϊ�");
			if(DIFFERSTR(env->querystr("name"), "����"))
				me->move(load_room("���괺������"));
			else
				me->move(load_room("���괺�̴��"));
		}
		else if(env->query("lj/wanxuanhuei")==1||(me->query("lj/renwu6")&&env->query("lj/wanxuanhuei")==atoi(me->id(1))))
		{
			if(!me->query("lj/renwu6"))
			{
				tell_object(me, "\n$HIC��Ȼ������ֻ��ǰ��¶��һ��ƻ𣬵ƻ𷢳������͵Ĺ�â���Ĳ�ͬѰ���ƻ��ɫ��������ơ�");
				tell_object(me, "\n$HIR��ʱ�����ﲻ��һ������������аħ������ڴ˾ۻ�!����ʱ��������ɦ��ԾԾ���ԡ�\n");
				env = load_room("���괺����");
				env->set("lj/wanxuanhuei",atoi(me->id(1)));
				env = load_room("���괺ѩ�޷�");
				env->set("lj/wanxuanhuei",atoi(me->id(1)));
				me->set("lj/renwu6",1);
				me->del("lj/renwu5");
			}
		}
		else if(env->query("lj/wanxuanhuei")>1)
		{
			tell_object(me, "\n$HIC��Ȼ������ֻ��ǰ��¶��һ��ƻ𣬵ƻ𷢳������͵Ĺ�â���Ĳ�ͬѰ���ƻ��ɫ��������ơ�");
			tell_object(me, "$HIC��ʱ�����ﲻ��һ������������аħ������ڴ˾ۻ�!����ʱ����������ɦ��ԾԾ���ԡ�");
			tell_object(me, "$HIC���ڴ�ʱ�����׸������и�����Ʈ�˹��������η����ˣ������ɴ�������ң����潫��ʮ������������ʮ�����������������������𣿡�");
			tell_object(me, "$HIC��Ȩ����һ�£���ס���棬��ͷ���˳�ȥ��");
			if(DIFFERSTR(env->querystr("name"), "����"))
				me->move(load_room("���괺������"));
			else
				me->move(load_room("���괺�̴��"));
		}
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env;
	env = load_room("���괺����");
	if(env->query("lj/wanxuanhuei"))
	{
		env->del("lj/wanxuanhuei");
		env = load_room("���괺ѩ�޷�");
		env->del("lj/wanxuanhuei");
		tell_room(me->environment(), "\n$BLK���ɴ���Ѫ���ĺ󣬴��ɱ�����չ���ȡ��ҩȥѽ����\n");
	}
	env = load_room("���괺�ó���");
	if(env->querymap("lj"))
		env->del("lj");
	destruct(me);
}

char * chat_msg()
{
	CContainer * env= load_room("���괺�ó���");
	if(env->query("lj/lost"))
	{
		env->del("lj/taolun");
		call_out(do_die, 5);
	}
	else if(env->query("lj/win"))
	{
		set("lj/sha",1);
		call_out(do_die, 5);
	}

	if(!random(50))
	{
		switch(random(12))
		{
		case 0:
			tell_room(environment(), "�Ŷ��������ȵ���������ţ����ռ���֮�����в�����������֪����");
			break;
		case 1:
			tell_room(environment(), "���͵͵�Ķ���կ��˽��������Ǳ����˵�����֪���ˣ����Ҵ�Ҷ��ⲻ��ɱ��֮����");
			break;
		case 2:
			tell_room(environment(), "�ﵺ�������߽е���ÿ��Ҫ����ЩС��Ƥ����ĥ�������ҿ��ܹ��ˣ�");
			break;
		case 3:
			tell_room(environment(), "�ֶ��������ֹ��ţ����������Ϲ��ﻹ��ɽ�ϡ���");
			break;
		case 4:
			tell_room(environment(), "�ܵ������Աߵ���˵�������¸��´�ȥ��һ�����壬Ҫ������ˣ������ǾͲ��ˡ�");
			break;
		case 5:
			tell_room(environment(), "�ζ�������һ�ںȵ����꣡С���㣡ǰ���ƺ��ж�����");
			break;
		case 6:
			tell_room(environment(), "������վ�ڴ�ʯ��ָ�ӵ���������ɽ��Ҫ���������в����߽�һ�����ˡ�");
			break;
		case 7:
			tell_room(environment(), "������̾�������øɴ࣬��Ҳ���ˡ��ɴ��Ҳ���ǽ����϶������صĺ��ӣ�ȴҪ����������������ĥ��");
			break;
		case 8:
			tell_room(environment(), "³����ҧ���ȵ������������ɱ����翷壬�ҵ�Ҫ��ЩС��Ƥ�������ӵ��������ٺ١���");
			break;
		case 9:
			tell_room(environment(), "���������Աߵ�����˵������������翷�������ʮ�꣬��֪����ǲ����Ѿ������ˡ���");
			break;
		case 10:
			tell_room(environment(), "������������ૣ������˵��԰����ǲ���������ֶ���������������ҳϵİɣ�");
			break;
		case 11:
			tell_room(environment(), "���ɶ�����������һ�𣬲�֪˭̾��һ�䣺������֪������ʲôʱ���������ᷢ����");
			break;
		}
	}
	return "";
}

virtual void die()
{
	tell_room(environment(), "\n$HIR�����ǲ���Ź����ǵģ�\n");
	destruct(this);
}

NPC_END;