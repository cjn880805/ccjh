//xy_liqiouheng3.h �����
//�ز� 2002��12��12

NPC_BEGIN(CNxy_liqiouheng3);

virtual void create()
{    
    set_name("�����", "li qiou heng");
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

    set_skill("force", 300);
    set_skill("xiaowuxiang", 300);
    set_skill("dodge", 300);
    set_skill("xiaoyao_bu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
	set_skill("literate", 280);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("gangdao")->wield();

	call_out(do_die, 1200);	
	set("chat_chance", 80);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

void bl_move()
{
	char msg[255];
	int i=query("xy/bl");
	
	static char bnline1[7][20]={"��ң�ȴ���Ǿ���2","��ң�ȴ���Ǿ���3","��ң�ȴ���Ǿ���4","��ң�ȴ���Ǿ���5","��ң�ȴ���Ǿ���6","��ң�ȴ���Ǿ���7","��ң�ȱչ���"};
	if(i==7)
	{
		CChar * XyNpc=(CChar *)(environment()->present("tong lao"));
		if(!XyNpc)
			XyNpc = load_npc("xy_tielao1");
		XyNpc->set("owner",querystr("owner"));
		((CUser *)XyNpc)->Ready_PK();
		((CUser *)this)->Ready_PK();
		this->kill_ob(XyNpc);	
		XyNpc->kill_ob(this);
		del("chat_chance");
	}
	else
	{
		message_vision(snprintf(msg, 255, "%s��%s��ȥ��",name(),bnline1[i]), this);
		CRoom * troom=load_room(bnline1[i]);
		move(troom);
		set("xy/bl",i+1);
	}
	return ;
}

char * chat_msg()
{
	if(!random(10))bl_move();
	return "";
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
			message_vision("\n$HIC����ۺ�Ȼ������ʦ�㣬�����һ���������ģ���\n", this);
			target->del("xy/renwu7_pause");
			tell_object(target,"$HIR���������գ�����ʦ����ɽ���ѱչ������ɹ����������������5000�㡣");
			target->add("combat_exp",5000);
			destruct(this);
			break;
		}
	}
}

NPC_END;




