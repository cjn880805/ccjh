NPC_BEGIN(CNdiyu_shizhe2);

virtual void create()		
{
	set_name("��Ȫʹ��", "huangquan shizhe2");
};

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	int a,b;
	CChar * tn;
	b=random(6);
	for(a=1;a<b;a++)
	{
		tn=	load_npc("dy2_monster");
		tn->set("chat_chance", 20);
		tn->move(environment());	
	}
	destruct(this);	
}

NPC_END;

