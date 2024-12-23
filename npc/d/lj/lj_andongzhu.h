//lj_andongzhu.h	��ʯ��������
//�ز� 2002��6��5

NPC_BEGIN(CNlj_andongzhu);

void create()
{
	set_name("������","an dongzhu");
	set("long", "�����ں�ʯ���İ�������ʮ����ǰ���ǽ����Ͻе����һ��������ֻ�������������ĥ������������");
	set("title", "��ʯ����");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("icon",young_man6);
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);
	set_weight(50000000);
	set("chat_chance", 80);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

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
};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env;
	env = load_room("���괺����");
	if(env->query("lj/wanxuanhuei"))
		tell_room(me->environment(), "\n$BLK���ɴ���Ѫ���ĺ󣬴��ɱ�����չ���ȡ��ҩȥѽ����\n");
	destruct(me);
}

char * chat_msg()
{
	CContainer * env= load_room("���괺�ó���");
	if(env->query("lj/lost"))
		call_out(do_die, 5);
	else if(env->query("lj/win"))
		set("lj/sha",1);
	return "";
}

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
}

virtual void die()
{
	tell_room(environment(), "�����ǲ���Ź����ǵģ�");
	destruct(this);
}
NPC_END;




