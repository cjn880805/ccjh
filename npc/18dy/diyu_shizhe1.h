
NPC_BEGIN(CNdiyu_shizhe1);

virtual void create()		
{
	set_name("รินฌสนี฿", "migong shizhe");
};

virtual void init(CChar *ob)
{	
	CNpc::init(ob);
	int a,b;
	CChar * tn;
	b=random(5);
	for(a=1;a<b;a++)
	{
		tn = load_npc("dy1_monster");
		tn->set("chat_chance", 20);
		tn->move(environment());	
	}
	destruct(this);	
}

NPC_END;
