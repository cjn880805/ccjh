NPC_BEGIN(CNdiyu_shizhe4);

virtual void create()		
{
	set_name("πÌ√≈ π’ﬂ", "gueimen shizhe");
};

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	int a,b;
	CChar * tn;
	b=random(7);
	for(a=1;a<b;a++)
	{
		tn=	load_npc("dy4_monster");
		tn->set("chat_chance", 20);
		tn->move(environment());	
	}
	destruct(this);	
}

NPC_END;

