//guanfu.h
EQUIP_BEGIN(CIguanfu)

virtual void create(int nFlag = 0)		
{
	set_name("�ٷ�", "guan fu");
	
	set("wield_position", WIELD_ARMOR);		
	set("unit", "��");
	set("material", "leather");

	set("long",	"һ����ɫ�ٷ���ǰ��������������");
	set_weight(1000);
	set("value", 1);
	
	set("apply/armor",10);
	set("apply/per",2);

	set("wield_msg","������$n��$Nҡ��һ�䣬ٲȻ��һ�������Ĺٳ��Թ�ģ����");
 	set("unwield_msg", "$N������$n����ү��������ʱ��Ȼ�޴棡");

	set("no_beg",1);

	call_out(do_armor, 5);
	call_out(do_die, 3600);	

};

static void do_armor(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env=(ob->environment())->environment();

	if(ob->query("equipped")==WIELD_ARMOR)
	{
		if(DIFFERSTR(ob->querystr("����"),env->name(1)) )
		{
			if(DIFFERSTR("fight_room",env->querystr("base_name")))
			{
				ob->set("����",env->name(1));
				
				CContainer * me=ob->environment();
				
				DTItemList * list = env->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj = list->GetNext(p);
					if(! obj->is_character()) continue; 
					CChar * target = (CChar *)obj;  
					if(userp(target))	continue;
					char msg[255];
					message_vision(snprintf(msg, 255,"$N��С��$Nߵ��%s���ˣ�",(CChar *)me->querystr("name")),target, (CChar *)me);
				}
			}
		}
	}
	ob->call_out(do_armor, 5);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("�"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
EQUIP_END;
