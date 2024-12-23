//xy_liqiouheng.h ����ۣ���ң��СԺ����NPC��
//�ز� 2002��12��12

NPC_BEGIN(CNxy_liqiouheng2);

virtual void create()
{    
    set_name("������Ů", "meng mian nv");
    set("long","������һϮ���Ƴ�����������֬��üĿ�续��������̬�򷽣���Ц֮�䣬һ�ɽ���̬֮��Ȼ������");	
    set("gender", "Ů��"); 
    set("age", 20);

    set("str", 20); 
    set("int", 20);
    set("con", 28);
    set("dex", 30);
    set("per", 40);

    set("icon",6);
	set("title","��ң��");
	create_family("��ң��", 1, "����");

    set("max_hp", 18000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 120); 
    set("combat_exp", 5000000); 

	set("chat_chance", 30);
	
	set("no_kill",1);

    set_skill("force", 200);
    set_skill("xiaowuxiang", 200);
    set_skill("dodge", 200);
    set_skill("xiaoyao_bu", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("blade", 200);
    set_skill("xiaoyao_dao", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
	set_skill("literate", 280);
	set_skill("music",200);
	set_skill("xiaoaojianghu",200);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
	map_skill("music", "xiaoaojianghu");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("xiao")->wield();

	call_out(do_die, 3600);	
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(querystr("owner"))
	{
		if(!strcmp(comm, "kill")  || !strcmp(comm, "fight") || !strcmp(comm, "cast"))
		{
			if(DIFFERSTR(querystr("owner"),me->querystr("id")))
			{
				message_vision("\n$N������$n��������������ͻȻһת����������������ֱ������Ļ����ң��޷�������\n", me, this);
				me->add("hp",-100);
				me->UpdateMe();
				me->start_busy(2);
				return 1;
			}
			if(!me->query_skill("music",1))
			{
				message_vision("\n$N������$n��������������ͻȻһת����������������ֱ������Ļ����ң��޷�������\n", me, this);
				me->add("hp",-100);
				me->UpdateMe();
				me->start_busy(2);
				return 1;
			}
			CContainer * weapon;
			if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "music"))
			{
				message_vision("\n$N������$n��������������ͻȻһת����������������ֱ������Ļ����ң��޷�������\n", me, this);
				me->add("hp",-100);
				me->UpdateMe();
				me->start_busy(2);
				return 1;
			}
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

virtual void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(EQUALSTR(querystr("owner"),target->id(1)))
		{
			message_vision("\n$HIC������Ů����˵�������ߣ��һ��������ģ���\n", this);
			target->del("xy/renwu7_pause");
			tell_object(target,"$HIR���������գ�����ʦ����ɽ���ѱչ������ɹ����������������5000�㡣");
			target->add("combat_exp",5000);
			destruct(this);
			break;
		}
	}
}
NPC_END;




